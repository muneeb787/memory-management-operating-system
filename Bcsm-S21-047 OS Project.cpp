#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}

void String_table_generator_oneBit(string arr[],int x,int Number_of_bits)
{
    string zeros;
    for(int i=0; i<Number_of_bits; i++)
    {
        zeros=zeros+"0";
    }
    for(int i=0; i<x; i++)
    {
        arr[i]=zeros;
    }

    for(int i =0; i<x; i++)
    {
        int k = Number_of_bits-1;
        int n=i;
        for(int j=Number_of_bits-1; n>0; j--)
        {
            int p = n%2;
            if(p==1)
            {
                arr[i][k] = '1';
            }
            else
            {
                arr[i][k] = '0';
            }
            n=n/2;
            k--;
        }
    }
}

void String_table_generator(string **arr,int x,int y,int Number_of_bits)
{
    string zeros;
    for(int i=0; i<Number_of_bits; i++)
    {
        zeros=zeros+"0";
    }
    for(int i=0; i<x; i++)
    {
        for( int j=0; j<y; j++)
        {
            arr[i][0]="Null";
            arr[i][1]=zeros;
        }
    }

    for(int i =0; i<x; i++)
    {
        int k = Number_of_bits-1;
        int n=i;
        for(int j=y-1; n>0; j--)
        {
            int p = n%2;
            if(p==1)
            {
                arr[i][1][k] = '1';
            }
            else
            {
                arr[i][1][k] = '0';
            }
            n=n/2;
            k--;
        }
    }
}

void string_arr_DisplayOneBit(string arr[],int x)
{
    for( int i=0; i<x; i++)
    {
        cout<<i<<" ";
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}

void string_arr_Display(string **arr,int x,int y)
{
    cout<<"-------------------"<<endl;
    cout<<"Pages"<<"\t"<<"Frame"<<endl;
    cout<<"-------------------"<<endl;
    for( int i=0; i<x; i++)
    {
        for( int j=0; j<y; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void Display_Memories(string **logical_arr,string **Physical_arr,int x,int y,int pageSize,int Segment_bit)
{
    cout<<"\n ------------------------------------- > Displaying < -------------------------------------\n"<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"Virtual Addresses"<<"\t\t\t\t\t\t\t"<<"Physical Addresses"<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    int br=0;
    for( int i=0; i<x; i++)
    {

        if(br==pageSize)
        {
            cout<<"--------------------------"<<"\t\t\t\t\t"<<"--------------------------"<<endl;
            br=0;
        }
        br++;
        if(logical_arr[i][0]!="Null")
        {
            setcolor(2);
        }
        if(i<10)
        {
            cout<<"0";
        }

        cout<<i<<"    ";
        for( int j=0; j<y; j++)
        {
            cout<<setw(10)<<logical_arr[i][j];
        }
        setcolor(7);
        cout<<"\t\t\t\t\t";
        if(i<10)
        {
            cout<<"0";
        }

        cout<<i<<"    ";
        if(Physical_arr[i][0]!="Null")
        {
            setcolor(2);
        }
        for( int j=0; j<y; j++)
        {
            cout<<setw(10)<<Physical_arr[i][j];
        }
        cout<<endl;
        setcolor(7);
    }
}


void Page_table(string **page_table,string Phy_frame[],string logi_page[],int x)
{
    for(int i=0; i<x; i++)
    {
        page_table[i][0] = logi_page[i];
        page_table[i][1] = Phy_frame[rand() % x];
    }
}



int main()
{

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout << "\t  * * *   *       *   *       *   * * *   *       *      * * *   * * *   * * *    *         **    * * *  " << endl;
    Sleep(50);
    cout << "\t    *     * *     *    *     *      *     * *     *    *           *     *    *   *        *      *       " << endl;
    Sleep(50);
    cout << "\t    *     *   *   *     *   *       *     *   *   *   *            *     * * *    *        ***    * * *  " << endl;
    Sleep(50);
    cout << "\t    *     *     * *      * *        *     *     * *    *           *     *    *   *        *          * " << endl;
    Sleep(50);
    cout << "\t  * * *   *       *       *       * * *   *       *      * * *   * * *   * * *     * * *    **    * * *  " << endl;
    Sleep(50);

    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\t\t\t\t====MEMORY MANAGEMENT - OPERATING SYSTEM====" << endl;
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout << "\n\n\t\t\t\t======================PROJECT BY=====================" << endl;
    Sleep(50);
    cout << "\n\n\n\t\t\t\tBCSM-S21-047--------------Muneeb Ahmad\n";
    Sleep(50);
    cout << "\t\t\t\t=============================================" << endl;
    Sleep(50);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    int Space_Size=0;
label:
    cout<<"Enter Logical/Physical Address Size (Space Size): ";
    cin>>Space_Size;

    if(!isPowerOfTwo(Space_Size))
    {
        setcolor(4);
        cout<<"Invalid Space Size!!!"<<endl;
        cout<<"Space Size Must be in power of 2"<<endl;
        setcolor(7);
        cout<<"Again ";
        goto label;
    }

    int Number_of_bits = (ceil(log2(Space_Size)));
    //cout<<"Number of Bits Are : "<<Number_of_bits<<endl;

label1:
    int Page_size = 0;
    cout<<"Enter Page Size: ";
    cin>>Page_size;

    if(!isPowerOfTwo(Page_size))
    {
        setcolor(4);
        cout<<"Invalid Page Number!!!"<<endl;
        cout<<"Page Number Must be in power of 2"<<endl;
        setcolor(7);
        cout<<"Again ";
        goto label1;
    }

    int Number_of_Pages = Space_Size/Page_size;
    cout<<"---- > Total Number of Pages Are : "<<Number_of_Pages<<endl;

    int Segment_bits = (ceil(log2(Number_of_Pages)));
    //cout<<"BreakBit Are : "<<Segment_bits<<endl;

    int offset_bits = Number_of_bits - Segment_bits;

    //cout<<"Offset Bits Are : "<<offset_bits<<endl;

    int Segment_Address_Size = pow(2,Segment_bits);
    int Offset_Address_Size = pow(2,offset_bits);


//Arrays For Logical Memory

    string Logical_main_Add[Segment_Address_Size];
    string Logical_Offset_Add[Offset_Address_Size];

    string **Logical_Add = new string *[Space_Size];
    for(int i=0; i<Space_Size; i++)
    {
        Logical_Add[i] = new string[2];
    }

//Arrays For Physical Memory

    string Physical_main_Add[Segment_Address_Size];
    string Physical_Offset_Add[Offset_Address_Size];

    string **Physical_Add = new string *[Space_Size];
    for(int i=0; i<Space_Size; i++)
    {
        Physical_Add[i] = new string[2];
    }

    String_table_generator_oneBit(Logical_main_Add,Segment_Address_Size,Segment_bits);
    String_table_generator_oneBit(Logical_Offset_Add,Offset_Address_Size,offset_bits);
    String_table_generator_oneBit(Physical_main_Add,Segment_Address_Size,Segment_bits);
    String_table_generator_oneBit(Physical_Offset_Add,Offset_Address_Size,offset_bits);

    String_table_generator(Logical_Add,Space_Size,2,Number_of_bits);
    String_table_generator(Physical_Add,Space_Size,2,Number_of_bits);




    cout<<"\n\nDisplaying Logical Main Address"<<endl;
    string_arr_DisplayOneBit(Logical_main_Add,Segment_Address_Size);
    //cout<<"\n\nDisplaying Logical Offset Address"<<endl;
    //string_arr_DisplayOneBit(Logical_Offset_Add,y);
    cout<<"\n\nDisplaying Physical Main Address"<<endl;
    string_arr_DisplayOneBit(Physical_main_Add,Segment_Address_Size);
    //cout<<"\n\nDisplaying Physical Offset Address"<<endl;
    //string_arr_DisplayOneBit(Physical_Offset_Add,y);

//    cout<<"\n\nDisplaying logical Address"<<endl;
//    string_arr_Display(Logical_Add,Space_Size,2);
//    cout<<"\n\nDisplaying Physical Address"<<endl;
//    string_arr_Display(Physical_Add,Space_Size,2);

    Display_Memories(Logical_Add,Physical_Add,Space_Size,2,Page_size,Segment_bits);



    string **Pagetable = new string *[Segment_Address_Size];
    for(int i=0; i<Segment_Address_Size; i++)
    {
        Pagetable[i] = new string[2];
    }

    Page_table(Pagetable,Logical_main_Add,Physical_main_Add,Segment_Address_Size);

    cout<<"\n\nDisplaying PageTable"<<endl;
    string_arr_Display(Pagetable,Segment_Address_Size,2);

    string Instruction;
label6:
    cout<<"\n\nEnter the Instruction : ";
    getline(cin >> ws, Instruction);

    int inc_place;
label3:
    cout<<"Enter Instruction Address (in Decimal) : ";
    cin>>inc_place;

    if(inc_place>Space_Size)
    {
        setcolor(4);
        cout<<"Invalid Space Size!!!"<<endl;
        cout<<"Space Size Must be in power of 2"<<endl;
        setcolor(7);
        cout<<"Again ";
        goto label3;
    }
    if(Logical_Add[inc_place][0]!="Null")
    {
        setcolor(4);
        cout<<"This Block Is Already filled With Another Instruction"<<endl;
        cout<<"Space Size Must be in power of 2"<<endl;
        setcolor(7);
        cout<<"Again ";
        goto label3;
    }

    Logical_Add[inc_place][0]=Instruction;

    string seg_logi,seg_phy,offset_logi,fin_add;

    for(int i =0; i<Segment_bits; i++)
    {
        seg_logi = seg_logi + Logical_Add[inc_place][1][i];
    }
    for(int i =Segment_bits; i<Number_of_bits; i++)
    {
        offset_logi = offset_logi + Logical_Add[inc_place][1][i];
    }

    cout<<"\nSegment address is: "<<seg_logi<<endl;
    cout<<"\nOffset address is: "<<offset_logi<<endl;

    for(int i = 0 ; i < Segment_Address_Size ; i++)
    {
        if(Pagetable[i][0]==seg_logi)
        {
            seg_phy=Pagetable[i][1];
            cout<<"\n\nIn PageTable -- "<<Pagetable[i][0]<<" <==> "<<Pagetable[i][1]<<endl;
        }
    }

    fin_add = seg_phy+offset_logi;

    for(int i =0 ; i<Space_Size; i++)
    {
        if(Physical_Add[i][1] == fin_add)
        {
            Physical_Add[i][0] = Instruction;
        }
    }

    cout<<"\n\nDisplaying Address Sheet"<<endl;
    Display_Memories(Logical_Add,Physical_Add,Space_Size,2,Page_size,Segment_bits);

    char a;
label5:
    cout<<"\n\n Do you Want to Enter Another Instruction (y/n) : ";
    cin>>a;
    if(a=='y' || a=='Y')
    {
        goto label6;
    }
    else if(a=='n' || a=='N')
    {
        exit(1);
    }
    else
    {
        setcolor(4);
        cout<<"Invalid Input:"<<endl;
        setcolor(7);
        goto label5;
    }
}
