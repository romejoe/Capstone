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
env = Environment(CCFLAGS=['-std=c89', '-ansi'],
				  CCCOMSTR = "Compiling $TARGET",
                  LINKCOMSTR = "Linking $TARGET",
                  ENV=os.environ,
                  tools=tools
                  )
#setup debugging
if GetOption('Debug'):
	env.Append(CCFLAGS='-g3')
	env.Append(CPPDEFINES=['__LEX_DEBUG__'])

SConscript('src/SConscript', variant_dir='build', exports='env')