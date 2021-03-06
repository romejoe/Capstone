top = "."

recurseDirs = ["Compiler", "Interpreter", "Common"]

def options(opt):
	opt.add_option("--Docs", "--BuildDocumentation", default=False, action='store_true', help="Build the Documentation")

	opt.recurse(recurseDirs)

def configure(conf):
	conf.recurse(recurseDirs)

	if conf.options.Docs:
		conf.load('tex')
		if not conf.env.LATEX:
			conf.msg('LaTex is missing! Without it, the documentation can\'t be built', "")
		if not conf.env.PDFLATEX:
			conf.msg('PDFLaTex is missing! Without it, the documentation can\'t be built', "")

def build(bld):
	bld.recurse(recurseDirs)
	
	if bld.env.PDFLATEX and bld.options.Docs:
		bld(
			features = 'tex',
			type = 'pdflatex',
			source = 'Documentation.tex'
			)

def test(ctx):
	from waflib import Options
	Options.commands = ['configure', 'clean', 'build'] + Options.commands
	# run basic tests
	print ctx.get_tgen_by_name('compiler')

from waflib.Build import BuildContext
class Test(BuildContext):
        cmd = 'test'
        fun = 'test'