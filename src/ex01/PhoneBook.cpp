/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:40:41 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/31 18:53:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Na inicialização do programa, a agenda está vazia e o usuário é
 * solicitado a inserir um dos três comandos. O programa aceita apenas ADD,
 * SEARCH e EXIT
 * @param ADD Metodo para salvar um novo contacto
 * 		@brief Se o usuário inserir este comando, ele será solicitado a inserir
 * 		as informações do novo contato, um campo por vez. Depois que todos
 * 		os campos forem preenchidos, adicione o contato à lista telefônica.
 *		@brief Os campos de contato são: nome, sobrenome, apelido, número
 *		de telefone e segredo mais obscuro. 
 *		Um contato salvo não pode ter campos vazios
 * @param SEARCH display a specific contact
 *		@brief Exibe os contatos salvos como uma lista de 4 colunas:
 *		índice, nome, sobrenome e apelido.
 *		@brief Cada coluna deve ter 10 caracteres de largura. 
 *		Um caractere de barra vertical ('|') os separa. 
 *		O texto deve estar alinhado à direita. Se o texto for maior que
 *		a coluna, ele deverá ser truncado e o último caractere exibível
 *		deverá ser substituído por um ponto (’.’).
 *		@brief Em seguida, solicite novamente ao usuário o índice da entrada
 *		a ser exibido. Se o índice estiver fora do intervalo ou errado, defina
 *		um comportamento relevante. Caso contrário, exiba as informações de 
 *		contato, um campo por linha.
 * @param EXIT The program quits and the contacts are lost forever!
 *		@brief Qualquer outra entrada é descartada.
 *		@brief Depois que um comando for executado corretamente, o programa 
 *		aguarda outro. Ele para quando o usuário digita EXIT.
 *		@brief Dê um nome relevante ao seu executável.
*/
PhoneBook::PhoneBook() : contactIndex(0) {}
PhoneBook::~PhoneBook() { std::cout << "PhoneBook deteled!" << std::endl; }
std::string	strlenCheck(std::string str);

void	PhoneBook::addContact(size_t index)
{
	Contact &contact = contacts[index];
	
	std::cout << "First name: ";
	std::cin >> contact.firstName;
	std::cout << "Last name: ";
	std::cin >> contact.lastName;
	std::cout << "Nickname: ";
	std::cin >> contact.nickName;
	std::cout << "Phone number: ";
	std::cin >> contact.phoneNumber;
	std::cout << "Dark secret: ";
	std::cin >> contact.darkSecret;
}

/**
 * @brief Adds a new contact to the phone book.
 * This function adds a new contact to the phone book.
 * If there is space available in the phone book, the contact is added at
 * the next available index. If the phone book is already full, the oldest 
 * contact is removed and the new contact is added at the end.
 * 
 * @param newContact The contact to be added.
 */
void	PhoneBook::Add(void)
{
	if (contactIndex == 8)
	{
		for (size_t i = 1; i < contactIndex; i++)
			contacts[i - 1] = contacts[i];
		contactIndex--;
	}
	addContact(contactIndex++);
}

void	PhoneBook::listContacts(size_t index)
{
	Contact &contact = contacts[index];

	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.nickName) << "|";
	std::cout << std::endl;
}

void	PhoneBook::showContact(size_t index)
{
	Contact &contact = contacts[index];

	std::cout << "|";
	std::cout << std::setw(10) << (index + 1) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.firstName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.lastName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.nickName) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.phoneNumber) << "|";
	std::cout << std::setw(10) << strlenCheck(contact.darkSecret) << "|";
	std::cout << std::endl;	
}

void	PhoneBook::Search(void)
{
	size_t	index(0);
	
	printHeader();
	for (size_t i = 0; i < contactIndex; i++)
		listContacts(i);
	std::cout << std::endl << "Insert index: ";
	std::cin >> index;
	index--;
	if (contactIndex == 0)
		std::cout << "Phonebook is empty!" << std::endl;
	else if (index < 0 || index > contactIndex)
		std::cout << "Ivalid index!" << std::endl;
	else
		showContact(index);		
}

std::string	strlenCheck(std::string str)
{
	if (str.length() > 9)
	{
		str = str.substr(0, 9);
		str = str + ".";
	}
	return (str);
}

void	PhoneBook::printHeader(void)
{
	std::cout << " _________________________________________________________________" << std::endl;
	std::cout << "|                                                                 |" << std::endl;
	std::cout << "|************************ PHONEBOOK APP***************************|" << std::endl;
	std::cout << "|*****************************************************************|" << std::endl;
	std::cout << "|************************ Instruction: ***************************|" << std::endl;
	std::cout << "|Save Contact: ADD | Search Contact: SEARCH | Phonebook end: EXIT |" << std::endl;
	std::cout << "|_________________________________________________________________|" << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::setw(10) << "Phone num." << "|";
	std::cout << std::setw(10) << "Dark sec." << "|";
	std::cout << std::endl;
}
