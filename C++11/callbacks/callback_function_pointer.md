**What is callback**:
Callback is a function that we pass to another APIs as argument while calling them.
Now these APIs are expected to use our provided callback at some point.

**Types of callback in C++**:
1] function_pointer
2] Function object/ functor
3] Lambda function


 **Function_Pointer**:
   Implement method which take string data, and second argument will be encrypt it by 1 or ecrypt it by -1 which will be decided at run time

//This encrypt function increment all letters in string by 1.
std::string encryptDataByLetterInc(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]++;
    }
    return data;
} 

//This encrypt function decrement all letters in string by 1.	
std::string encryptDataByLetterDec(std::string data)
{
    for(int i = 0; i < data.size(); i++)
    {
        if( (data[i] >= 'a' && data[i] <= 'z' ) || (data[i] >= 'A' && data[i] <= 'Z' ) )
            data[i]--;
    }
    return data;
}

std::string buildCompleteMessage(std::string rawData, std::string (* encrypterFunPtr)(std::string) )
{
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";
 
    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encrypterFunPtr(rawData);
 
    return rawData;
}


call method:
buildCompleteMessage("Hello World", &encryptDataByLetterInc);

OR

buildCompleteMessage("Hello World", &encryptDataByLetterDec);