#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("os_project");
MODULE_AUTHOR("Amisha Mathew");

// Kernel Module to list all tasks from init to the current task
// and their respective PIDs print the tasks in the tree format

void print_task_tree(struct task_struct *task, int depth)
{
    int i;
    struct task_struct *child;
    struct list_head *list;

    for (i = 0; i < depth; i++)
        printk("--");

    printk("%s[%d]\n", task->comm, task->pid);

    list_for_each(list, &task->children) {
        child = list_entry(list, struct task_struct, sibling);
        print_task_tree(child, depth + 1);
    }
}

// Module Initialization
static int __init Task_Displayer_init(void)
{
    printk(KERN_INFO "Task Displayer: Module Loaded\n");
    printk(KERN_INFO "Task Displayer: Listing all tasks from init to current task\n");
    print_task_tree(&init_task, 0);
    return 0;
}
// Module Exit
static void __exit Task_Displayer_exit(void)
{
    printk(KERN_INFO "Task Displayer: Module Unloaded\n");
}
// Call the init and exit functions
module_init(Task_Displayer_init);
module_exit(Task_Displayer_exit);