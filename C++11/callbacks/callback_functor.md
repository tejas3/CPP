**Function Object/Functor**:
Functor means object which behave like a function is called Functor.
In other words, object of a class which has oveloaded operator() is called function object.

Example:

class A
{
  public:
  int operator()(int x, int y)
  {
     return x+y;
  }
};

int main()
{
  A obj;
  cout<< obj(2, 3);

// equivalent to
  obj.operator()(2, 3);
}

In function pointer we had seen that we incremented and decremented using function pointer.
Now we want to increment by 1, 2, or decrement by 1 according to requirement

**if we use function pointer then we have to code**
//This encrypt function increment all letters in string by 1.
std::string encryptDataByLetterInc1(std::string data) {
    for (int i = 0; i < data.size(); i++)
        if ((data[i] >= 'a' && data[i] <= 'z')
                || (data[i] >= 'A' && data[i] <= 'Z'))
            data[i]++;
    return data;
}
//This encrypt function increment all letters in string by 2.
std::string encryptDataByLetterInc2(std::string data) {
    for (int i = 0; i < data.size(); i++)
        if ((data[i] >= 'a' && data[i] <= 'z')
                || (data[i] >= 'A' && data[i] <= 'Z'))
            data[i] = data[i] + 2;
    return data;
}
//This encrypt function increment all letters in string by 1.
std::string encryptDataByLetterDec(std::string data) {
    for (int i = 0; i < data.size(); i++)
        if ((data[i] >= 'a' && data[i] <= 'z')
                || (data[i] >= 'A' && data[i] <= 'Z'))
            data[i] = data[i] - 1;
    return data;
}

int main() {
    std::string msg = buildCompleteMessage("SampleString",
            &encryptDataByLetterInc1);
    std::cout << msg << std::endl;
 
    msg = buildCompleteMessage("SampleString", &encryptDataByLetterInc2);
    std::cout << msg << std::endl;
 
    msg = buildCompleteMessage("SampleString", &encryptDataByLetterDec);
    std::cout << msg << std::endl;
 
    return 0;
}





**Alternative way is**: Functor

class Encryptor {
    bool m_isIncremental;
    int m_count;
public:
    Encryptor() {
        m_isIncremental = 0;
        m_count = 1;
    }
    Encryptor(bool isInc, int count) {
        m_isIncremental = isInc;
        m_count = count;
    }
    std::string operator()(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
                if (m_isIncremental)
                    data[i] = data[i] + m_count;
                else
                    data[i] = data[i] - m_count;
        return data;
    }
 
};

// builder method

std::string buildCompleteMessage(std::string rawData,
        Encryptor encyptorFuncObj) {
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";
 
    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encyptorFuncObj(rawData);
 
    return rawData;
}

int main() {
    std::string msg = buildCompleteMessage("SampleString", Encryptor(true, 1)); inc by 1
    std::cout << msg << std::endl;
 
    msg = buildCompleteMessage("SampleString", Encryptor(true, 2)); // inc by 2
    std::cout << msg << std::endl;
 
    msg = buildCompleteMessage("SampleString", Encryptor(false, 1));  // decrement by 1
    std::cout << msg << std::endl;
 
    return 0;
}