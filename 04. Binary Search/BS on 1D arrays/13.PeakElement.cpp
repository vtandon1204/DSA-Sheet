int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        // if (n == 1) {
        //     return 0;
        // }
        // if (arr[0] > arr[1]) {
        //     return 0;
        // }
        // if (arr[n - 1] > arr[n - 2]) {
        //     return n - 1;
        // }
        while (s <= e) {
            int mid = s + (e - s) / 2;

            bool leftCheck = (mid == 0) || (arr[mid] > arr[mid - 1]);
            bool rightCheck = (mid == n - 1) || (arr[mid] > arr[mid + 1]);

            if (leftCheck && rightCheck) {
                return mid;
            }
            else if (leftCheck) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }