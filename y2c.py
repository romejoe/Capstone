from waflib import Task

class y2c(Task.Task):
	run_str= '${SRC}'
	run_str= '${SRC[0].abspath()} ${SRC[1].abspath()}'
	color='GREEN'
	ext_out = ['.h']
	nocache = True
	#def signature(self):
		
	#	import hashlib
	#	m = hashlib.md5()
	#	m.update("qwerty")
	#	return m.hexdigest()
		#sig = super(Task.Task, self).signature()
		#delattr(self, 'cache_sig')
		#return super(Task.Task, self).signature()
		

from waflib.TaskGen import extension

@extension('.y')
def process_y(self, node):
	tg = self.bld.get_tgen_by_name('lemon')
	c_node = node.change_ext('.c')
	h_node = node.change_ext('.h')
	lemon = tg.link_task.outputs[0]
	tsk = self.create_task('y2c', [lemon, node], None)
	#self.source.extend(tsk.outputs)
	#self.source.append(tsk.outputs)
	self.source.append(c_node)
	#self.source.append(h_node)
