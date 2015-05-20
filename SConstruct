import os

#handle debug builds
AddOption('--Debug', action='store_true', dest='Debug', default=False)
AddOption('--Release', action='store_false', dest='Debug', default=True)

#handle documentation
AddOption('--WithDocs', action='store_true', dest='WithDocs', default=True)
AddOption('--WithoutDocs', action='store_false', dest='WithDocs', default=False)

tools = ['default', 'textfile']
if GetOption('WithDocs'):
	tools += ['pdf', 'pdftex']
env = Environment(CXXFLAGS=['--std=c++11', '-Wno-deprecated-register'],
				  CCCOMSTR = "Compiling $TARGET",
                  LINKCOMSTR = "Linking $TARGET",
                  ENV=os.environ,
                  tools=tools
                  )
#setup debugging
if GetOption('Debug'):
	env.Append(CCFLAGS='-g')
	env.Append(CXXFLAGS='-g')
	env.Append(CPPDEFINES=['__LEX_DEBUG__'])

SConscript('src/SConscript', variant_dir='build', exports='env')