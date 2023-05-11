#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<climits>
/**
 * Funktio tarkastaa ettei käyttäjä syötä muuta kuin sallittuja numeroita
*/
bool is_valid_num(const std::string& user_input){

    for(char c : user_input){
        if(!std::isdigit(c))
        {
            std::cout << "Input only an integer number." << std::endl;
            return false;

        }
    }
    return true;

}
/**
 * Funktio täyttää vektorin käyttäjän syöttämillä numeroilla
 * käyttäjän syöte tarkastetaan
*/
void fill_vector(std::vector<int>& vector_of_ints, int vec_size){
    int i = 0;
    while(i < vec_size){
        std::string s = "";
        std::cout << "Input a number: ";
        std::cin >> s;
        if(!is_valid_num(s)){
            continue;
        }
        else{
            vector_of_ints.push_back(std::stoi(s));
            i++;
        }
    }
    
}

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    std::string user_input = "";
    while(true){
        
        cout << "Input how many integers the vector should have: ";
        cin >> user_input;
        if(is_valid_num(user_input)){
            break;
        }

    }
    
    int vec_size = std::stoi(user_input);
    std::vector<int> vector_of_ints = {};
    
    //täytetään vektori
    fill_vector(vector_of_ints, vec_size);

    int sum_of_vec = 0;
    int min_elem = INT_MAX;
    int max_elem = INT_MIN;
    int max_count = 1;
    int current_count = 1;
    int result = 0;
    std::unordered_map<int,int> ints; //alustetaan unordered_map numeroiden toistuvuuden seurantaa varten
    std::vector<int> same_frequency; // luodaan vektori jaetun tasasijan varalta

    for(int i = 0; i < vector_of_ints.size(); i++){
        sum_of_vec += vector_of_ints.at(i); //summataan alkiot yhteen
        min_elem = std::min(min_elem, vector_of_ints.at(i)); //päivitetään minimi elementtiä
        max_elem = std::max(max_elem, vector_of_ints.at(i)); // päivitetään maksimi elementtiä
        ints[vector_of_ints[i]]++; // lisätään luvut unordered_mappiin
    }
    //käydään unordered_map läpi ja etsitään toistuvin numero
    for(auto value : ints){
        if(value.second > max_count){
            result = value.first;
            max_count = value.second;
        }
    }
    //käydään uudestaan läpi ja tarkastetaan onko jaettu tasasija
    for(auto value : ints){
        if(value.second == max_count){
            same_frequency.push_back(value.first);
        }
    }    
    float average = sum_of_vec / vec_size;
    cout << std::endl;
    cout << "Sum of vector: " << sum_of_vec << std::endl;
    cout << "Average number: " << average << std::endl;
    cout << "Smallest number: " << min_elem << std::endl;
    cout << "Largest number: " << max_elem << std::endl;
    //tulostetaan numerot, jotka esiintyvät eniten, mutta yhtä useasti
    if(same_frequency.size() > 1){
        cout << "Numbers ";
        for(auto num : same_frequency){
            cout << num << " ";           
        }
        cout << "appeared " << max_count << " times. " << endl;
    }
    else{
        cout << "The most frequent number: " << result << std::endl;
    }
    cout << "The difference between minium and maxium value is: " << max_elem - min_elem << std::endl;
    return 0;
}