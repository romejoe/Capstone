def options(opt):
	opt.load("compiler_c")

def configure(conf):
	from waflib.Tools.compiler_c import c_compiler
	conf.load('compiler_c')

def build(bld):
	bld.program(features='c', source='demo.c', target='demo')
	