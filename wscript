top = "."

recurseDirs = ["Compiler", "Interpreter", "Common", "Documentation"]

def options(opt):
	opt.add_option("--Docs", "--BuildDocumentation", default=False, action='store_true', help="Build the Documentation")

	opt.add_option("--onlyDocs", "--OnlyDocumentation", default=False, action='store_true', help="Build only the documentation")
	opt.recurse(recurseDirs)

def configure(conf):
	
	if conf.options.Docs or conf.options.onlyDocs:
		conf.load('tex')
		if not conf.env.LATEX:
			conf.msg('LaTex is missing! Without it, the documentation can\'t be built', "")
		if not conf.env.PDFLATEX:
			conf.msg('PDFLaTex is missing! Without it, the documentation can\'t be built', "")
	if not conf.options.onlyDocs:
		conf.recurse(recurseDirs)
	else:
		conf.recurse(["Documentation"])

def build(bld):
	if not bld.options.onlyDocs:
		bld.recurse(recurseDirs)
	
	if bld.env.PDFLATEX and (bld.options.Docs or bld.options.onlyDocs):
		bld(
			features = 'tex',
			type = 'pdflatex',
			source = 'Documentation.tex'
			)
		bld.recurse(["Documentation"])

def test(ctx):
	from waflib import Options
	Options.commands = ['configure', 'clean', 'build'] + Options.commands
	# run basic tests
	print ctx.get_tgen_by_name('compiler')

from waflib.Build import BuildContext
class Test(BuildContext):
        cmd = 'test'
        fun = 'test'