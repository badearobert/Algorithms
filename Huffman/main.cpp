/******************************************************************************
* Copyright (C) 22/05/2017
*
* @file         main.cpp
* @project		Algorithms / Huffman
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <string>
#include "Huffman.hpp"
#include "Helper.hpp"

using namespace NAlgorithms;
using namespace NHuffman;
using namespace NHelper;

const std::string StringToEncode = "robertbadea.ro";

int main()
{
	// Build frequency table from a given string
	FrequencyMap frequencyMap;
	for (auto const & i : StringToEncode)
	{
		frequencyMap[i]++;
	}

	// Debugging purposes - display the frequency map
	for (auto const & i : frequencyMap)
	{
		std::cout << i.first << " = " << i.second << std::endl;
	}

	// Generate the tree
	INode* root = GenerateTree(frequencyMap);

	// Generate Huffman codes based on the tree
	HuffmanCodes codes;
	GenerateCode(root, PrefixQueue(), codes);

	// Debugging purposes - display the huffman codes for each character
	std::cout << "----------------\n";
	for (const auto & code : codes)
	{
		std::cout << code.first << " = " << GetQueueData(code.second) << std::endl;
	}

	//Display the full encoded message
	PrefixQueue encodedMessage;
	for (const auto& i : StringToEncode)
	{
		PrefixQueue temp = codes[i];
		while (!temp.empty())
		{
			encodedMessage.push(temp.front());
			temp.pop();
		}
	}

	std::cout << "Encoded message is : " << GetQueueData(encodedMessage) << std::endl;

	// Display the decoded message
	std::string message = GetDecodedMessage(encodedMessage, root);
	std::cout << "Message is : " << message << std::endl;

	std::cin.get();

	return 0;
}
