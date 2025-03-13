#include "token.hpp"

// exercice1

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    for (size_t i{0}; i < s.size(); i++)
    {
        if (std::isdigit(s[i]) || i == '.')
            continue;
        else
            return false;
    }
    return true;
}

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack{};
    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            float token_as_float{std::stof(token)};
            stack.push(token_as_float);
        }
        else
        { // Je récupère l'élément en haut de la pile
            float rightOperand{stack.top()};
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand{stack.top()};
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result{token == "+" ? rightOperand + leftOperand : token == "-" ? rightOperand - leftOperand
                                                                 : token == "*"   ? rightOperand * leftOperand
                                                                 : token == "/"   ? rightOperand / leftOperand
                                                                 : token == "^"   ? pow(rightOperand, leftOperand)
                                                                                  : 0};
            stack.push(result);
        }
    }
    if (stack.size() == 1)
    {
        return stack.top();
    }
    else
        return 0;
}

// exercice 2

Token make_token(float value)
{
    return {TokenType::OPERAND, value};
}

Token make_token(Operator op)
{
    return {TokenType::OPERATOR, 0, op};
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> result{};
    for (std::string word : words)
    {
        if (is_floating(word))
        {
            result.push_back(make_token(std::stof(word)));
        }
        else
        {
            if (word == "+")
            {
                result.push_back(make_token(Operator::ADD));
            }
            else if (word == "-")
            {
                result.push_back(make_token(Operator::SUB));
            }
            else if (word == "*")
            {
                result.push_back(make_token(Operator::MUL));
            }
            else if (word == "/")
            {
                result.push_back(make_token(Operator::DIV));
            }
            else if (word == "^")
            {
                result.push_back(make_token(Operator::POW));
            }
        }
    }
    return result;
}

float npi_evaluate(std::vector<Token> const &tokens)
{
    std::stack<float> stack{};
    for (Token token : tokens)
    {
        if (token.type == TokenType::OPERAND)
        {
            stack.push(token.value);
        }
        else
        { // Je récupère l'élément en haut de la pile
            float rightOperand{stack.top()};
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand{stack.top()};
            stack.pop();

            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result{token.op == Operator::ADD ? rightOperand + leftOperand : token.op == Operator::SUB ? rightOperand - leftOperand
                                                                              : token.op == Operator::MUL   ? rightOperand * leftOperand
                                                                              : token.op == Operator::DIV   ? rightOperand / leftOperand
                                                                              : token.op == Operator::POW   ? pow(rightOperand, leftOperand)
                                                                                                            : 0};
            stack.push(result);
        }
    }
    if (stack.size() == 1)
    {
        return stack.top();
    }
    else
        return 0;
}