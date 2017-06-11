/*Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Note:
Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '*/

/*
思路：
最开始写的算法是把整个字符串还原出来，但大数据会超时，于是看了别人的代码，发现可以通过和num比较来判断，不需还原
*/

class StringIterator {
public:
    StringIterator(string compressedString) : cs(compressedString), index(0), num(0), ch(' '){}
    
    char next() {
        if(num > 0) {
            num --;
            return ch;
        }
        else if(index < cs.length()) {
            ch = cs[index ++];
            string count = "";
            while(index < cs.length() && isdigit(cs[index])) {
                count += cs[index ++];
            }
            num = stoi(count) - 1;
            return ch;
        }
        else {
            return ' ';
        }
    }
    
    bool hasNext() {
        return index < cs.length() || num > 0;
    }
private:
    int index, num;
    string cs;
    char ch;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
