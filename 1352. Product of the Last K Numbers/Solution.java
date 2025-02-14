class ProductOfNumbers {
    // list to store prefix (cumulative) products
    // the first element is initialized to 1 as a dummy value to simplify calculations
    List<Integer> prefixProducts;

    public ProductOfNumbers() {
        prefixProducts = new ArrayList<>();
        prefixProducts.add(1);
    }

    public void add(int num) {
        // when a zero is added, reset the prefixProducts list
        // and we want subsequent getProduct calls to correctly return 0 for sequences including the zero
        if(num == 0) {
            prefixProducts.clear();
            prefixProducts.add(1); // reinitialize with base value
        } else {
            int lastProduct = prefixProducts.get(prefixProducts.size() - 1);
            prefixProducts.add(lastProduct * num);
        }
    }

    public int getProduct(int k) {
        int size = prefixProducts.size();

        // if k is greater than or equal to the number of elements in prefixProducts
        // => the range of k numbers includes a zero (reset point)
        if(k >= size) {
            return 0;
        }

        // compute the product of the last k numbers
        // the product is derived by dividing the total cumulative product (last element)
        // by the cumulative product just before the sequence of the last k numbers
        int result = prefixProducts.get(size - 1) / prefixProducts.get(size - k - 1);

        return result;
    }
}