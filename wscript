top = "."

recurseDirs = ["Compiler"]

def options(opt):
	opt.recurse(recurseDirs)

def configure(conf):
	conf.recurse(recurseDirs)

	conf.load('tex')
	if not conf.env.LATEX:
		conf.msg('LaTex is missing! Without it, the documentation can\'t be built', "")
	if not conf.env.PDFLATEX:
		conf.msg('PDFLaTex is missing! Without it, the documentation can\'t be built', "")

def build(bld):
	bld.recurse(recurseDirs)

	if bld.env.PDFLATEX:
		bld(
			features = 'tex',
			type = 'pdflatex',
			source = 'Documentation.tex'
			)
def test(ctx):
	ctx.recurse(recurseDirs)