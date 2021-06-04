def create_heap(letters_dict, code_len):
    heap = [0 for _ in range(code_len * 2 + 1)]
    root = 0
    for i in letters_dict:
        for j in letters_dict[i]:
            root = root * 2 + 1 if j == '0' else root * 2 + 2
        heap[root] = i
        root = 0
    return heap
 
def huffman_decode(tree, encode_str):
    root = 0
    decode_str = ''
    for i in encode_str:
        root = root * 2 + 1 if i == '0' else root * 2 + 2
        if tree[root] != 0:
            decode_str += tree[root]
            root = 0
    return decode_str
 
def main():
    in_first_line = input().split(' ')
    count_letters = int(in_first_line[0])
    code_len = int(in_first_line[1])
    letters_dict = {};
    for i in range(count_letters):
        in_line = input().split(': ')
        letters_dict[in_line[0]] = in_line[1]
    code = input()
    huffman_tree = create_heap(letters_dict, code_len)
    result = huffman_decode(huffman_tree, code)
    print(result)
 
if __name__ == '__main__':
    main()
