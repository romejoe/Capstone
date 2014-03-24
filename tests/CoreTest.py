import unittest
import os
import os.path as path
from subprocess import Popen, PIPE

class CoreTestCase(unittest.TestCase):
	def _getBuildRoot(self):
		buildPath = os.getcwd()
		while not path.exists(path.join(buildPath, "build")):
			buildPath = path.join(buildPath, "..")
		return path.join(path.join(buildPath, "build"))

	def _runToolChainTest(self, name):
		buildPath = self._getBuildRoot()
		compilerPath = path.join(buildPath, "Compiler", "compiler")
		interpreterPath = path.join(buildPath, "Interpreter", "interpreter")
		srcPath = name + ".lan"
		dstPath = name + ".out"
		buildOutputPath = name + "_output.log"

		compilationProcess = Popen([compilerPath, srcPath, dstPath], stdout=PIPE, stderr=PIPE)
		compilationResults = compilationProcess.communicate()
		self.assertTrue(compilationProcess.returncode == 0)
		self.assertTrue(path.exists(dstPath), "CompilationFailed")
		
		with open(buildOutputPath, "w") as log:
			log.write("STDERR:\n")
			log.write(compilationResults[0])
			log.write("STDOUT:\n")
			log.write(compilationResults[1])

		interpretationProcess= Popen([interpreterPath, dstPath], stdout=PIPE, stderr=PIPE)
		interpretationResults = interpretationProcess.communicate()
		self.assertIsNotNone(interpretationResults)
		return interpretationResults

	def _runParserTest(self, name):
		buildPath = self._getBuildRoot()
		parserPath = path.join(buildPath, "Compiler", "parserTest")
		
		srcPath = name + ".lan"
		buildOutputPath = name + "_output.log"

		parserProcess = Popen([parserPath, srcPath], stdout=PIPE, stderr=PIPE)
		parserResults = parserProcess.communicate()
		self.assertTrue(parserProcess.returncode == 0)
		
		return parserResults
