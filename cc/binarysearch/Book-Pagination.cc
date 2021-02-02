// O(n) time
vector<string> solve(vector<string>& book, int page, int page_size) {
    vector<string> res;
    for(int i = page_size * page; i < min(page_size * (page + 1), (int)book.size()); i+= 1){
        res.push_back(book[i]);
    }
    return res;
}
