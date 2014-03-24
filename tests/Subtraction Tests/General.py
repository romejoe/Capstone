import unittest
import CoreTest

class SymbolTestCase(CoreTest.CoreTestCase):
    def test_Symbols(self):
		results = self._runParserTest("SymbolTests")
		testString = "STDERR:\n" + results[0] + "STDOUT:\n" + results[1]
		with open("SymbolTests_ParserOutput.txt", "r") as f:
			test = f.read()
			self.assertTrue(testString == test)

if __name__ == "__main__":
    unittest.main()