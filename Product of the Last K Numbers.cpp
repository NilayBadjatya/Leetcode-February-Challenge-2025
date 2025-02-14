class ProductOfNumbers {
public:
    vector<int> a;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        a.push_back(num);
    }
    
    int getProduct(int k) {
        int product = 1, count = k;
        for(int i = a.size() - 1; i >= 0 && count > 0; i--){
            product *= a[i];
            count--;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
