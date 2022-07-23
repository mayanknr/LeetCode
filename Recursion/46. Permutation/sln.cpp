#include<iostream>
#include<vector>

using namespace std;

void generate(char* input,char* output,int i,int j){
if(input[i]=='\0')
{
    output[j]='\0';
    cout<<output<<endl;
    return;
}
    
output[j]=input[i];
generate(input,output,i+1,j+1);

generate(input,output,i+1,j);


}

void gen2(char* input,vector<char> output,int i)
{
    if(input[i]=='\0')
{
    for(int i=0;i<output.size();i++)
    cout<<output[i];
    cout<<endl;
    return;
}
    
output.push_back(input[i]);
gen2(input,output,i+1);

output.pop_back();
gen2(input,output,i+1);

}
int main()
{
    char input[4]={'a','b','c','\0'};
    char output[100];
    vector<char> o;

   generate(input,output,0,0);
cout<<"---------------"<<endl;
gen2(input,o,0);

}
