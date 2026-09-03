#include <iostream>
#include "LinkTree.h"
#include "DynamicArray.h"
int main ()
{
    // LinkTree tree;
    // TreeNode *n1 = new TreeNode(1);
    // TreeNode *n2 = new TreeNode(2);

    // n1->Connect(tree.GetRoot());
    // n2->Connect(tree.GetRoot());

    // TreeNode *n3 = new TreeNode(3);
    // TreeNode *n4 = new TreeNode(4);
    // TreeNode *n5 = new TreeNode(5);

    // n3->Connect(n1); 
    // n4->Connect(n2);
    // n5->Connect(n4);

    // tree.show();
    LinkTree tree;
    TreeNode *class1 = new TreeNode("267班");
    TreeNode *class2 = new TreeNode("268班");

    class1->Connect(tree.GetRoot());
    class2->Connect(tree.GetRoot());

    TreeNode *stu1 = new TreeNode("张三");
    TreeNode *stu2 = new TreeNode("李四");
    TreeNode *stu3 = new TreeNode("王五");
    TreeNode *stu4 = new TreeNode("赵六");

    stu1->Connect(class1);
    stu2->Connect(class1);
    stu3->Connect(class2);
    stu4->Connect(class2);

    tree.show();

    TreeNode *node = tree.FindByElement("赵六");
    node->Disconnect(tree.FindByElement("268班"));
    node->Connect(tree.FindByElement("267班"));
    tree.show();
    std::cout<<"树高："<<tree.GetTreeHeight()<<std::endl;;
    return 0;
}
