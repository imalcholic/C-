#include<iostream>
using namespace std;
class String
{
    private:
      string s;
    public:
    
      // TAKING SINGLE WORD STRING
      void singleWordString();
    
      // TAKING MULTI WORD STRING
      void multiWordString();
    
      // DISPLAYING STRING
      void displayString();
    
      // FINDING LENGTH USING COUNTER
      void lengthOfString();
    
      /* FINDING LENGTH USING .lenth()
        method */
      void lengthOfStringMethod();
    
    /* CHANGING CASES 
      1. UPPER TO LOWER
      2. LOWER TO UPPER
      3. TOGGLE        */
      void upperToLower();
      void lowerToUpper();
      void toggle();
    
    // COUNTING VOWEL & CONSONENT
      void countVowelAndConsonent();
    
    // COUNTING WORD IN SENTENCE
      void countingWord();
    
    /*VALID STRING 
      If string each character in between
      A to Z or a-z   */
      
      void validString();
    
    /* REVERSING STRING 
      1. USING EXTRA ARRAY
      2. USING SAME ARRAY WITH TWO COUNTER
    */
    
      void reverseStringWithArray();
      void reverseStringTwoCounter();
    
    /* PALINDROME STRING OR NOT
      1. Using two counter & compare
      2. Using other Array & compare
    */
      void palindromeSameString();
      void palindromeWithArray();
    
    //COMPARING STRING
      void comparingString();
    
    /* Check Duplicate character in String
      1.brute force approach
      2.Using Hash Table (countable)
      3.Bitwise operator (Not countable)
    */
      
      void checkDuplicateBruteForce();
    
    //Anagram
    //Backtracking
};

void String::singleWordString()
{
    cout<<"Enter single word string :";
    cin>>s;
}

void String::multiWordString()
{
    cout<<"Enter multi word string :";
    getline(cin,s);
}

void String::displayString()
{
    cout<<s;
}

void String::lengthOfString()
{
    int i;
    for( i=0 ; s[i]!='\0' ; i++)
    {
    
    }
    cout<<"length of string :"<<i;
}

void String::lengthOfStringMethod()
{
    cout<<"Length of string :";
    //cout<<s.length();
    cout<<s.size();
}

void String::upperToLower()
{
    //for(int i=0; s[i]!='\0' ; i++)
    for(int i=0 ; i<s.length() ;i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            s[i] =s[i]+32;
    
    }
    displayString();
}

void String::lowerToUpper()
{
    //for(int i=0 ; s[i]!='\0' ; i++)
    for(int i=0 ;i<s.length() ; i++)
    {
        if(s[i]>='a' && s[i]<='z')
            s[i] = s[i]-32;
    
    }
    displayString();
    
    
}

void String::toggle()
{
    for(int i=0 ; i<s.length() ; i++)
    {
        if(s[i]>='a' && s[i]<='z')
            s[i] = s[i] -32;
        
        else if(s[i]>='A' && s[i]<='Z')
           s[i] = s[i] +32 ;

    }
    displayString();
}

void String::countVowelAndConsonent()
{
    int vCount=0;
    int cCount=0;
    
    for(int i=0 ; i<s.length() ;i++)
    {
        if(s[i]=='A' || s[i]=='E'  || s[i]=='I' || s[i]=='O' || s[i]=='U'|| s[i]=='a'  || s[i]=='e'|| s[i]=='i' || s[i]=='o'  || s[i]=='u')
        {
           vCount++;
        }
        
        else if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
        {
           cCount++;
       }
    
    }
    cout<<endl;
    cout<<"Vowel : "<<vCount<<endl;
    cout<<"Consonent : "<<cCount<<endl;
    
}

void String::countingWord()
{
    int count=1;
    for(int i=0 ; s[i]!='\0' ; i++)
    {
        if(s[i]==' ' && s[i-1]!=' ')
          count++;
   
    }
    cout<<"Total "<<count<<" word in sentence"<<endl;
    
}

void String::validString()
{
    bool flag=true;
    for(int i=0 ; s[i]!='\0' ; i++)
    {
        if(!(s[i]>='a' && s[i]<='z')     &&    !(s[i]>='A' && s[i]<='Z')&& !(s[i]>='0' && s[i]<='9'))
        {
           cout<<"Invalid string";
            flag=false;
            break;
        }
    
    }
    if(flag)
      cout<<"Valid string";
}

void String::reverseStringWithArray()
{
    int length=s.length();
    length=length+1;
    char *C =new char[length];
    int i,j;
    length=s.length();
    for(i=length-1,j=0;i>=0;i--,j++)
    {
        C[j]=s[i];
    }
    C[j]='\0';
    
    for(i=0 ; C[i]!='\0' ;i++)
    {
        cout<<C[i];

    }
}

void String::reverseStringTwoCounter()
{
    int i,j;
    int length=s.length();
    length=length-1;
    for(i=0,j=length;i<j;i++,j--)
    {
        char temp=s[i];
        s[i] =s[j];
        s[j] =temp;

    }
    displayString();
}

void String::palindromeSameString()
{
    int i,j;
    bool flag=true;
    int length=s.length();
    length =length-1;
    for(i=0,j=length ;i<j;i++,j--)
    {
        if(s[i]!=s[j])
        {
           cout<<"Not palindrome";
           flag=false;
           break;
        }
    
    }
    if(flag)
      cout<<"Palindrome";
}

void String::palindromeWithArray()
{
    int length=s.length();
    length =length+1;
    char * A=new char[length];
    
    length=s.length();
    length=length-1;
    int i,j;
    for(i=0,j=length;j>=0;j--,i++)
    {
        A[i]=s[j];

    }
    A[i]='\0';
    
    bool flag=true;
    
    for(i=0;i<s.length();i++)
    {
       if(A[i]!=s[i])
        {
           cout<<"Not palindrome";
           flag=false;
           break;
        }
    }
    if(flag)
       cout<<"Palindrome";
}

void String::comparingString()
{
    string s2;
    cout<<"Enter another string:";
    getline(cin,s2);
    bool flag=true;
    int i,j;
 for(i=0,j=0;s[i]!='\0' ||s2[j]!='\0';i++,j++)
    {
        if(s[i]!=s2[j])
        {
           cout<<"Different string";
           flag=false;
           break;
        
        }

    }
    if(flag)
      cout<<"Same string";
    
}
/*
void String::checkDuplicateBruteForce()
{
    int i,j;
    
    int count ;
    int size=s.size();
    size =size-1;
    
    for(i=0 ;i<size;i++)
    {
        count=1;
       if(s[i]!=0)
       {
        for(j=i+1 ; i<s.size();j++)
        {
            if(s[i]==s[j] && s[i]!=' ')  
            { 
                count++;
                s[j]=0;
             
             
            }
        
        }
        if(count>1)
        {
            cout<<"Duplicate character :";
            cout<<s[i];
            cout<<" Times :"<<count<<endl;
        
        }
       }

    }
}
*/
int main()
{
    String s;
    
    //s.singleWordString();
    s.multiWordString();
  
    //s.lengthOfString();
    //s.lengthOfStringMethod();
    
    //s.upperToLower();
    //s.lowerToUpper();
    //s.toggle();
   
    //s.countVowelAndConsonent();
    
    //s.countingWord();
    
    //s.validString();
    
    //s.reverseStringWithArray();
    //s.reverseStringTwoCounter();
    
    //s.palindromeSameString();
    //s.palindromeWithArray();
    
    //s.comparingString();
   
     s.checkDuplicateBruteForce();
    
    //s.displayString();
    
    return 0;

}