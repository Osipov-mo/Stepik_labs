#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Huffman{
    struct CharSetFrequency{
        string char_set;
        int frequency;

        bool operator < (const CharSetFrequency &other) const {
            return tie(frequency, char_set) > tie(other.frequency, other.char_set);
        }
    };

public:
    static unordered_map<char, string> encode(const string &text);
    static string decode(const string &text, const unordered_map<char, string> &huffman_encoding);
};

unordered_map<char, string> Huffman::encode(const string &text){
    uap<char, int> char_frequencies;
    for(auto c:text){
        char_frequencies[c]++;
    }

    vector<CharSetFrequency> frequencies;
    for(auto char_frequency:char_frequencies){
        frequencies.push_back({string(1,char_frequency.first), char_frequency.second});
    }

    if(frequencies.size() == 1){
        unordered_map<char, string> result;
        result[frequencies[0].char_set[0]] = "0";
        return result;
    }

    unordered_map<char, string> result;
    priority_queue<CharSetFrequency> q(frequencies.begin(), frequencies.end());
    while(q.size()>=2){
        auto first = q.top();
        q.pop();
        auto second = q.top();
        q.pop();

        for(auto c:first.char_set){
            result[c] = "0" + result[c];
        }

        for(auto c:second.char_set){
            result[c] = "1" + result[c];
        }

        q.push({first.char_set + second.char_set, first.frequency + second.frequency});
    }
    return result;
}

string Huffman::decode(const std::string &text, const unordered_map<char, string> &huffman_encoding){
    size_t len = text.size();
    size_t pos = 0;
    string result;
    while(pos < len){
        for(auto &encoded:huffman_encoding){
            if(text.substr(pos, encoded.second.size()) == encoded.second){
                result += encoded.first;
                pos += encoded.second.size();
                break;
            }
        }
    }
    return result;
}

int main(){
    string text;
    cin >> text;

    auto huffman_encoding = Huffman::encode(text);

    string encoded_text;
    for(auto c:text){
        encoded_text += huffman_encoding[c];
    }
    cout << huffman_encoding.size() << " " << encoded_text.size() << endl;
    for(auto &encoded : huffman_encoding){
        cout << encoded.first << ": " << encoded.second << std::endl;
    }
    cout << encoded_text << endl;
}
