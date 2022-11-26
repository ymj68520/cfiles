extern int puts(const char * __s);

//主菜单
void showhlep(){
    puts("------------------------------------------------");
    puts("This information management system is powerful, so you can use it to perform the operation you want");
    puts("It includes viewing, deleting, and inserting information, as well as executing exit procedures.");
    puts("------------------------------------------------");
    //puts("");
    return;    
}
//查看
void showcheck(){
    puts("------------------------------------------------");
    puts("1:Check includes student information check and grade check.");
    puts("\tCheck information includes personal information view and all information view.");
    puts("\tPersonal information viewing lists only the details of a specific person.");
    puts("\tThe full information view will list all the people in the existing information base.");
    puts("You can also arbitrarily swap the order of two students by their serial numbers.");
    puts("------------------------------------------------");
    return;
}
//删除
void showdel(){
    puts("------------------------------------------------");
    puts("2:The delete function supports you to delete the information of a student.");
    puts("\tYou will be asked which objects you want to remove.");
    puts("\tYou can delete it by typing the student's serial number, name, or student number.");
    puts("\tThe system will remind you to change a method when you input a certain item with duplicate information.");
    puts("\tIt is recommended that you delete the information by the student's serial number.");
    puts("------------------------------------------------");
    return;
}
//插入
void showins(){
    puts("------------------------------------------------");
    puts("3:The insert operation allows you to insert information into an existing database.");
    puts("\tYou need to enter the corresponding information according to the system prompt.");
    puts("Please do not enter at will, otherwise the system will prompt you to input error and ask you to enter again.");
    puts("Of course you can enter more than one information at a time, but please follow the prompts.");
    puts("------------------------------------------------");
    return;
}
//退出
void showex(){
    puts("------------------------------------------------");
    puts("The exit function will exit the program. Please think twice before you do so.");
    puts("Of course, the system will prompt you if you need to quit.");
    puts("------------------------------------------------");
    return;
}

// help of check
void hcheck_show(){
    puts("");
}
void hcheck_order(){

}
void hcheck_add(){

}
void hcheck_del(){
    puts("------------------------------------------------");
    puts("This deletion function is mainly divided ");
    puts("into all deletion and individual deletion.");
    puts("In all deletion, we will ask you to confirm ");
    puts("twice whether you need to delete all, in ");
    puts("case you delete by mistake ");
    puts("In a case delete, you can delete one or more"); 
    puts("student information by specifying a serial ");
    puts("number, name, or student number .");
    puts("------------------------------------------------");
}

void Insert_hel(){
    
}