#pragma once
/******************************************************************************
* Copyright (C) 22/05/2017
*
* @file         Huffman.hpp
* @project		Algorithms / Huffman
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* Main class that contain the Huffman function declaration
*****************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <iostream>
#include <queue>
#include <map>
#include "DataStructures.hpp"

namespace NAlgorithms
{
	namespace NHuffman
	{
		/**
		* Map of frequencies.
		* Contains the number of times a character is used in a given phrase
		**/
		using FrequencyMap = std::map<char, uint32_t>;

		/**
		* The encoded bits for a given character - the road from the root to the corresponding leaf
		**/
		using PrefixQueue = std::queue<bool>;

		/**
		* The map containing the huffman codes.
		* Each character is given a series of encoded bits.
		* Using those bits, we are able to reach it using the tree structure
		**/
		using HuffmanCodes = std::map<char, PrefixQueue>;

		/**
		* Generate the tree based on frequency map.
		* Returns the root node
		**/
		INode* GenerateTree(FrequencyMap& frequencyMap);

		/**
		* Fill the HuffmanCodes map received as ref by iterating through the tree
		**/
		void GenerateCode(INode* node, PrefixQueue prefix, HuffmanCodes& codes);
	} // NHuffman

} // NAlgorithms



