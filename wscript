top = "."

recurseDirs = ["Compiler"]

def options(opt):
	opt.recurse(recurseDirs)

def configure(conf):
	conf.recurse(recurseDirs)

def build(ctx):
	ctx.recurse(recurseDirs)