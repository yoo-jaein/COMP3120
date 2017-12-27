#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init init_hello(void) {
	printk("[COMP3120]: Hello, Kernel. I am Jaein\n");

	return 0;
}

static void __exit exit_hello(void) {
	printk("[COMP3120]: Good bye, Kernel\n");
}

module_init(init_hello);
module_exit(exit_hello);
MODULE_LICENSE("GPL");

