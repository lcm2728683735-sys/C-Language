// #include <iostream>
// #include <mysql/mysql.h>

// int main ()
// {
//     MYSQL mysql; //数据库的句柄
//     mysql_init(&mysql);

//     const char *host = "192.168.191.129";
//     //返回指针为空,连接失败
//     if(!mysql_real_connect(&mysql,host,"root","as158158","test",3306,nullptr,0))
//     {
//         std::cout <<"连接失败!\n";
//         return -1;
//     }
//     std::cout<<"连接成功!\n";

//     //执行数据库语句
//     std::string sql = "insert into student values (100,'zhaoliu');";
//     int res = mysql_real_query(&mysql,sql.c_str(),sql.size());
//     if(res == 0)
//     {
//         //获取查找的结果集
//         MYSQL_RES * result = mysql_store_result(&mysql);
//         if(result != nullptr)
//         {
//             //获取列名
//             MYSQL_FIELD *field = mysql_fetch_field(result);
//             //获取列数
//             int field_count = mysql_field_count(&mysql);

//             for(int i = 0; i < field_count;i++)
//             {
//                 std::cout<<field[i].name<<" "<<std::endl;
//             }
//             std::cout << std::endl;

//             //获取每一行数据
//             MYSQL_ROW row;
//             while(row = mysql_fetch_row(result))
//             {
//                 for(int i = 0;i < field_count; i++)
//                 {
//                     std::cout<<row[i]<<" ";
//                 }
//                 std::cout << std::endl;
//             }
//         }

//     }
//     else
//     {
//         std::cout<<mysql_error(&mysql)<<std::endl;
//     }
//     mysql_close(&mysql);
//     return 0;
// }