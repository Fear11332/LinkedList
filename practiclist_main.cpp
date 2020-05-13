#include <iostream>
#include "practiclist.h"

using namespace std;

int main()
{
List lst;
size_t numbers_count;

cout<<"enter list size"<<endl;
cin>>numbers_count;
cout<<endl;

for(int i = 0 ; i<numbers_count ; i++)
{
	lst.push_back(rand()%10);
}

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<endl;
cout<<"reverse list "<<endl;
lst.reverse();

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<endl;
cout<<"copy constructor was called"<<endl;
List lst2(lst);

cout<<"list2 size = "<<lst2.GetElementsCounter()<<endl;

for(int i=0 ; i<lst2.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst2[i];
}

cout<<endl;
cout<<endl;
cout<<"enter list3 size"<<endl;
cin>>numbers_count;
cout<<endl;
List lst3;
for(int i = 0 ; i<numbers_count ; i++)
{
	lst3.push_back(rand()%10);
}

cout<<"list3 size = "<<lst3.GetElementsCounter()<<endl;

for(int i=0 ; i<lst3.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst3[i];
}

cout<<endl;
cout<<endl;
cout<<"list2 = list3"<<endl;
lst2 = lst3;

cout<<"list2 size = "<<lst2.GetElementsCounter()<<endl;

for(int i=0 ; i<lst2.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst2[i];
}


cout<<endl;
cout<<endl;
cout<<"enter position node in list for show address"<<endl;
size_t pos;
cin>>pos;
cout<<endl;
cout<<"show node in list address position:"<<pos<<endl;
cout<<lst.getNode(pos)<<endl;


cout<<endl;
cout<<"removeNextNode position " <<pos<<":"<<endl;
lst.removeNextNode(lst.getNode(pos));

cout<<endl;
cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}


cout<<endl;
cout<<"insert:"<<endl;
lst.insert(12,2);

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<"enter position for removeAt"<<endl;
cin>>pos;
cout<<endl;
cout<<"removeAt position "<<pos<<":"<<endl;
lst.removeAt(pos);

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<"push_front:"<<endl;
lst.push_front(8);

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
ValueType value;
cout<<"enater your value for find index "<<endl;
cin>>value;
cout<<"your index for value = "<<value<<" is: "<<lst.findIndex(value)<<endl;


cout<<endl;
cout<<"enater your value for find address"<<endl;
cin>>value;
cout<<"your address for value = "<<value<<" is: "<<lst.findNode(value)<<endl;


cout<<endl;
cout<<"pop_front:"<<endl;
lst.pop_front();

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<"insertAfterNode:"<<endl;
cout<<"enter node position"<<endl;
cin>>pos;
lst.insertAfterNode(lst.getNode(pos),17);

cout<<"list size = "<<lst.GetElementsCounter()<<endl;
for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<"pop_back:"<<endl;
lst.pop_back();

cout<<"list size = "<<lst.GetElementsCounter()<<endl;

for(int i=0 ; i<lst.GetElementsCounter() ; i++)
{
	cout<<"elements index "<<i<<'=';
	lst[i];
}

cout<<endl;
cout<<"clear all list:"<<endl;
lst.clear();
lst2.clear();
lst3.clear();

cout<<"list size = "<<lst.GetElementsCounter()<<endl;


return 0;
}

