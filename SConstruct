#handle debug builds
AddOption('--Debug', action='store_true', dest='Debug', default=False)
AddOption('--Release', action='store_false', dest='Debug', default=True)

#handle documentation
AddOption('--withDocs', action='store_true', dest='WithDocs', default=True)
AddOption('--withoutDocs', action='store_false', dest='WithDocs', default=False)

env = Environment(CCFLAGS=['-std=c89', '-ansi'])

if GetOption('Debug'):
	env.Append(CCFLAGS='-g3')
	env.Append(CPPDEFINES=['__LEX_DEBUG__'])

FlexBuilder = Builder(action = 'flex -o $TARGET $SOURCE')
env['BUILDERS']['Flex'] = FlexBuilder
SConscript('src/SConscript', variant_dir='build', exports='env')