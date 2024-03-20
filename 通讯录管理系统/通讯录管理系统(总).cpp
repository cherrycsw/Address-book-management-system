#include<iostream>
#include<string>
using namespace std;

//定义联系人结构体
struct ContactPerson {
	string name;
	string sex;
	int age;
	string phoneNumber;
	string address;
};

//功能函数：

//菜单
void menu() {
	cout << "****************************************" << endl;
	cout << "**************1、添加联系人*************" << endl;
	cout << "**************2、显示联系人*************" << endl;
	cout << "**************3、删除联系人*************" << endl;
	cout << "**************4、查找联系人*************" << endl;
	cout << "**************5、修改联系人*************" << endl;
	cout << "**************6、清空联系人*************" << endl;
	cout << "**************0、退出通讯录*************" << endl;
	cout << "****************************************" << endl;
}

//添加联系人
int insertContactPerson(ContactPerson contactPerson[]) {
	string inName;
	string inSex;
	int inAge;
	string inPhoneNumber;
	string inAddress;
	int i = 0;
	cout << "姓名："<<endl;
	cin >> inName;
	cout << "性别：" << endl;
	cin >> inSex;
	cout << "年龄：" << endl;
	cin >> inAge;
	cout << "电话号码：" << endl;
	cin >> inPhoneNumber;
	cout << "地址：" << endl;
	cin >> inAddress;
	while (contactPerson[i].name != "") {
		i++;
	}
	if (i >= 0 && i <= 1000) {
		contactPerson[i].name = inName;
		contactPerson[i].sex = inSex;
		contactPerson[i].age = inAge;
		contactPerson[i].phoneNumber = inPhoneNumber;
		contactPerson[i].address = inAddress;
	}
	else {
		cout << "超过限定的联系人数1000，请删除联系人后再添加！" << endl;
	}
	return 0;
}

//显示联系人
void printContactPerson(ContactPerson contactPerson[]) {
	for (int i = 0; i < 1000;i++) {
		if (contactPerson[0].name=="") {
			cout << "联系人为空！" << endl;
			break;
		}
		if (contactPerson[i].name!="") {
			cout << "姓名：" << contactPerson[i].name << "\t性别：" << contactPerson[i].sex << "\t年龄：" << contactPerson[i].age
				<< "\t电话：" << contactPerson[i].phoneNumber << "\t地址：" << contactPerson[i].address << endl;
		}
	}
}

//删除联系人
int deleteContactPerson(ContactPerson contactPerson[]) {
	string delName;
	cout << "请输入要删除联系人的姓名：" << endl;
	cin >> delName;
	for (int i = 0; i < 1000;i++) {
		if (contactPerson[i].name == delName) {
			if (i == 999) {
				contactPerson[i] = {};
			}
			else {
				while (contactPerson[i + 1].name != "") {
					contactPerson[i] = contactPerson[i + 1];
					i++;
				}
				contactPerson[i] = {};
				break;
			}	
		}
		if (i==999& contactPerson[i].name != delName) {
			cout << "没有你想删除的联系人！" << endl;
			return 1;
		}
	}
	return 0;
}

//查找联系人
void searchContactPerson(ContactPerson contactPerson[]) {
	string searName;
	cout << "请输入要查找联系人的姓名：" << endl;
	cin >> searName;
	if (contactPerson[0].name == "") {
		cout << "联系人为空！请添加联系人!" << endl;
	}
	else {
		for (int i = 0; i < 1000;i++) {
			if (contactPerson[i].name == searName) {
				cout << "姓名：" << contactPerson[i].name << "\t性别：" << contactPerson[i].sex << "\t年龄：" << contactPerson[i].age
					<< "\t电话：" << contactPerson[i].phoneNumber << "\t地址：" << contactPerson[i].address << endl;
				break;
			}
			if (i == 999 && contactPerson[i].name != searName) {
				cout << "查无此人！" << endl;
			}
		}
	}
}

//修改联系人
int updateContactPerson(ContactPerson contactPerson[]) {
	string updName;
	cout << "请输入要修改联系人的姓名：" << endl;
	cin >> updName;
	string newName;
	string newSex;
	int newAge;
	string newPhoneNumber;
	string newAddress;

	if (contactPerson[0].name == "") {
		cout << "联系人为空！无法修改!" << endl;
	}
	else {
		for (int i = 0; i < 1000; i++) {
			if (contactPerson[i].name == updName) {
				cout << "请输入姓名：" << endl;
				cin >> newName;
				cout << "请输入性别：" << endl;
				cin >> newSex;
				cout << "请输入年龄：" << endl;
				cin >> newAge;
				cout << "请输入电话：" << endl;
				cin >> newPhoneNumber;
				cout << "请输入地址：" << endl;
				cin >> newAddress;
				contactPerson[i].name = newName;
				contactPerson[i].sex = newSex;
				contactPerson[i].age = newAge;
				contactPerson[i].phoneNumber = newPhoneNumber;
				contactPerson[i].address = newAddress;
				break;
			}
			if (i == 999 && contactPerson[i].name != updName) {
				cout << "通讯录中不存在你要修改的联系人！" << endl;
			}
		}
	}
	return 0;
}

//清空联系人
void clearContactPerson(ContactPerson contactPerson[]) {
	memset(contactPerson, 0, 1000);
	cout << "已清空！" << endl;
}


//主函数
int main() {
	
	//联系人定义
	ContactPerson contactPerson[1000] = {};

	
	int FLAG = 0;
	//功能循环体
	while (1) {
		system("cls");
		menu();
		int functionNumber;
		cin >> functionNumber;

		switch (functionNumber) 
		{
		case 1: {
			int status1 = insertContactPerson(contactPerson);
			if (status1 == 0) {
				cout << "添加成功！" << endl;
			}
			else {
				cout << "添加失败！" << endl;
			}
			system("pause");
			break;
		}
			
		case 2:
			printContactPerson(contactPerson);
			system("pause");
			break;
		case 3: {
			int status2 = deleteContactPerson(contactPerson);
			if (status2 == 0) {
				cout << "删除成功！" << endl;
			}
			else {
				cout << "删除失败！" << endl;
			}
			system("pause");
			break;
		}
		case 4:
			searchContactPerson(contactPerson);
			system("pause");
			break;
		case 5: {
			int status3 = updateContactPerson(contactPerson);
			if (status3 == 0) {
				cout << "修改成功！" << endl;
			}
			else {
				cout << "修改失败！" << endl;
			}
			system("pause");
			break;
		}
		case 6:
			clearContactPerson(contactPerson);
			system("pause");
			break;
		case 0:
			FLAG = 1;
			break;
		default:
			cout << "抱歉！没有您所输入的功能序号，请确保您输入的功能序号在0-6范围内，请重新输入！"<<endl;
			system("pause");
			break;
		}

		if (FLAG == 1) {
			break;
		}
	}
	
	return 0;
}