function bubbleSort(arr){
    let n = arr.length;
    for(let i=0; i<n-1; i++){
        for(let j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
            }
        }
    }
    return arr;
}

function selectionSort(arr){
    let n =arr.length;
    let minIndex;
    for(let i=0; i<n-1; i++){
        minIndex = i;
        for(let j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
    return arr;
}

function insertionSort(arr){
    let n=arr.length;
    for(let i=1; i<n; i++){
        let key = arr[i];
        let j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}

function merge(arr, i, mid, j){
    let n1 = mid-i+1;
    let n2 = j-mid;
    let L = new Array(n1);
    let R = new Array(n2);
    for(let x=0; x<n1; x++){
        L[x] = arr[i+x];
    }
    for(let y=0; y<n2; y++){
        R[y] = arr[mid+1+y];
    }
    let k=i, x=0, y=0;
    while(x<n1 && y<n2){
        if(L[x]<=R[y]){
            arr[k] = L[x];
            x++;
        }else{
            arr[k] = R[y];
            y++;
        }
        k++;
    }
    while(x<n1){
        arr[k] = L[x];
        x++;
        k++;
    }
    while(y<n2){
        arr[k] = R[y];
        y++;
        k++;
    }
}

function mergeSort(arr,i,j){
    if(i>=j) return;
    let mid = Math.floor((i+j)/2);
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
    merge(arr, i, mid, j);
}

function swap(arr, i, j){
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

let arr = [5, 3, 8, 4, 2];
console.log("Bubble sort",bubbleSort(arr)); 
arr = [5, 3, 8, 4, 2];
console.log("Selection Sort",selectionSort(arr)); 
arr = [5, 3, 8, 4, 2];
console.log("Insertion Sort",insertionSort(arr)); // [2, 3, 4, 5, 8]
arr = [5, 3, 8, 4, 2, 3, 3, 87, 89, 23];
mergeSort(arr, 0, arr.length-1);
console.log("Merge Sort",arr); // [2, 3, 4, 5, 8]
