# Template aliases
* **Semantically similar to using a typedef however, template aliases with using are easier to read and are compatible with templates.**

```
using Vec = std::vector<int>;
Vec<int> v{}; // std::vector<int>

using String = std::string;
String s{"foo"};
```
