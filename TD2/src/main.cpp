#include  "token.hpp"


//exercice1


// int main()
// {
//     std::string test{};
//     std::cout << "Entrez l'operation en NPI :";
//     std::getline(std::cin, test);

//     std::vector<std::string> test_tokens{};
//     test_tokens = split_string(test);

//     std::cout << "Le resultat est :" << npi_evaluate(test_tokens) << std::endl;
// }




// exercice2


int main(){
    std::string test{};
    std::cout << "Entrez l'operation en NPI :";
    std::getline(std::cin, test);

    std::vector<std::string> test_tokens{};
    test_tokens = split_string(test);

    std::cout << "Le resultat est :" << npi_evaluate(tokenize(test_tokens)) << std::endl;
}