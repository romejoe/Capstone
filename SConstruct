import os

#handle debug builds
AddOption('--Debug', action='store_true', dest='Debug', default=False)
AddOption('--Release', action='store_false', dest='Debug', default=True)

#handle documentation
AddOption('--WithDocs', action='store_true', dest='WithDocs', default=True)
AddOption('--WithoutDocs', action='store_false', dest='WithDocs', default=False)

tools = ['default']
if GetOption('WithDocs'):
	tools += ['pdf', 'pdftex']
env = Environment(CCFLAGS=['-std=c89', '-ansi'],CCCOMSTR = "Compiling $TARGET",
                         LINKCOMSTR = "Linking $TARGET", ENV=os.environ,tools=tools)

if GetOption('Debug'):
	env.Append(CCFLAGS='-g3')
	env.Append(CPPDEFINES=['__LEX_DEBUG__'])

FlexBuilder = Builder(action = 'flex -o $TARGET $SOURCE')
env['BUILDERS']['Flex'] = FlexBuilder
import atexit

def print_build_failures():
    from SCons.Script import GetBuildFailures
    for bf in GetBuildFailures():
        print "%s failed: %s" % (bf.node, bf.errstr)
atexit.register(print_build_failures)



SConscript('src/SConscript', variant_dir='build', exports='env')