// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;


// void print(vector<string> arr){
// 	for(int i = 0 ; i < arr.size(); i++){
// 		for(int j = 0 ; j < arr[0].length(); j++){
// 				cout<<arr[i][j];//<<" ";
// 		}
//         cout<<endl;
// 	}
// }
// bool canplacehor(vector<string> arr,string word,int i,int j){
//     if(j - 1 >=0 && arr[i][j-1] != '+'){
//         return false;
//     }
//     else if(j+word.length() <= arr[0].length() && arr[i][j+word.length()] != '+')
//         return false;
    
//     for(int jj=0;jj<word.length();jj++){
//         if(j+jj >= arr[0].length())
//             return false;
//         if(arr[i][j + jj] == '-' || arr[i][j+jj] == word[jj]) 
//             continue;
//         else 
//             return false;
//     }
//     return true;
// }
// bool canplacever(vector<string> arr,string word,int i,int j){
//     if(i-1 >= 0 && arr[i-1][j] != '+'){
//         return false;
//     }
//     else if(i+word.length() <= arr.size() && arr[i + word.length()][j] != '+')
//         return false;
    
//     for(int ii=0 ; ii<word.length() ;ii++){
//         if(i+ii >= arr.size())
//             return false;
//         if(arr[i + ii][j] == '-' || arr[i + ii][j] == word[ii]) 
//             continue;
//         else 
//             return false;
//     }
//     return true;
// }
// vector<bool> placewordH(vector<string> &arr,string word,int i,int j){
//     vector<bool> wePlaced(word.length(),false);
//     for(int jj = 0 ; jj < word.length() ; jj++){
//         if(arr[i][j + jj] == '-'){
//             wePlaced[jj] = true;
//             arr[i][j + jj] = word[jj];
//         }
//     }
//     return wePlaced;
// }
// void unplacewordH(vector<string> &arr,vector<bool> wePlaced,int i,int j){
//     for(int jj = 0;jj < wePlaced.size();jj++){
//         if(wePlaced[jj] == true){
//             arr[i][j + jj] = '-';
//         }
//     }
// }vector<bool> placewordV(vector<string> &arr,string word,int i,int j){
//     vector<bool> wePlaced(word.length(),false);
//     for(int ii = 0 ; ii < word.length() ; ii++){
//         if(arr[i + ii][j] == '-'){
//             wePlaced[ii] = true;
//             arr[i + ii][j] = word[ii];
//         }
//     }
//     return wePlaced;
// }
// void unplacewordV(vector<string> &arr,vector<bool> wePlaced,int i,int j){
//     for(int ii = 0;ii < wePlaced.size();ii++){
//         if(wePlaced[ii] == true){
//             arr[i + ii][j] = '-';
//         }
//     }
// }
// void solution(vector<string> &arr, vector<string> words, int vidx){
    
//     if(vidx == words.size()){
//         print(arr);
//         return;
//     }
    
//     string word = words[vidx];
//     for(int i = 0;i<arr.size();i++){
//         for(int j = 0;j<arr[0].length();j++){
//             if(arr[i][j] == '-' || arr[i][j] == word[0]){
//                 if(canplacehor(arr,word,i,j)){
//                     vector<bool> wePlaced(word.length(),false);
//                     for(int jj = 0 ; jj < word.length() ; jj++){
//                         if(arr[i][j + jj] == '-'){
//                             wePlaced[jj] = true;
//                             arr[i][j + jj] = word[jj];
//                         }
//                     }
//                     // vector<bool> wePlaced = placewordH(arr,word,i,j);
//                     solution(arr,words,vidx+1);
//                     for(int jj = 0;jj < wePlaced.size();jj++){
//                         if(wePlaced[jj] == true){
//                             arr[i][j + jj] = '-';
//                         }
//                     }
//                     // unplacewordH(arr,wePlaced,i,j);
//                 }
//                 if(canplacever(arr,word,i,j)){
//                     // vector<bool> wePlaced = placewordV(arr,word,i,j);
//                     vector<bool> wePlaced(word.length(),false);
//                     for(int ii = 0 ; ii < word.length() ; ii++){
//                         if(arr[i + ii][j] == '-'){
//                             wePlaced[ii] = true;
//                             arr[i + ii][j] = word[ii];
//                         }
//                     }
//                     solution(arr,words,vidx+1);
//                     // unplacewordV(arr,wePlaced,i,j);
//                     for(int ii = 0;ii < wePlaced.size();ii++){
//                         if(wePlaced[ii] == true){
//                             arr[i + ii][j] = '-';
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }
#include <bits/stdc++.h>
using namespace std;

int ways = 0;
void printMatrix(vector<string>& matrix, int n)
{
    for (int i = 0; i < n; i++)
        cout << matrix[i] << endl;
}
vector<string> checkHorizontal(int x, int y,vector<string> matrix,string currentWord)
{
    int n = currentWord.length();
  
    for (int i = 0; i < n; i++) {
        if (matrix[x][y + i] == '-' || 
            matrix[x][y + i] == currentWord[i]) {
            matrix[x][y + i] = currentWord[i];
        }
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
  
    return matrix;
}
vector<string> checkVertical(int x, int y,vector<string> matrix,string currentWord)
{
    int n = currentWord.length();
  
    for (int i = 0; i < n; i++) {
        if (matrix[x + i][y] == '-' || 
            matrix[x + i][y] == currentWord[i]) {
            matrix[x + i][y] = currentWord[i];
        }
        else {
  
            // this shows that word
            // cannot be placed vertically
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}
void solvePuzzle(vector<string>& words,vector<string> matrix,int index, int n)
{
    if (index < words.size()) {
        string currentWord = words[index];
        int maxLen = n - currentWord.length();
  
        // loop to check the words that can align vertically.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkVertical(j, i,
                                        matrix, currentWord);
  
                if (temp[0][0] != '@') {
                    solvePuzzle(words, temp, index + 1, n);
                }
            }
        }
  
        // loop to check the words that can align horizontally.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= maxLen; j++) {
                vector<string> temp = checkHorizontal(i, j,
                                      matrix, currentWord);
  
                if (temp[0][0] != '@') {
                    solvePuzzle(words, temp, index + 1, n);
                }
            }
        }
    }
    else {
        // calling of print function to
        // print the crossword puzzle
        // cout << (ways + 1) << " way to solve the puzzle "<< endl;
        printMatrix(matrix, n);
        cout << endl;
  
        // increase the ways
        ways++;
        return;
    }
}
int main(){
    vector<string> arr;
    string s;
    for(int i=0;i<10;i++){
        cin>>s;
        arr.push_back(s);
    }
    int n;
    cin>>n;
    vector<string> words;
    for(int i =0 ;i<n;i++){
        cin>>s;
        words.push_back(s);
    }
    // print(arr);
    // for(int i = 0 ;i< words.size();i++)
        // cout<<words[i]<<" ";
    solvePuzzle(words,arr,0,10);
}