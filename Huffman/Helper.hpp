#pragma once
/******************************************************************************
* Copyright (C) 22/05/2017
*
* @file         Helper.hpp
* @project		Algorithms / Huffman
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* Helper functions, for debugging purposes
*****************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <string>
#include "Huffman.hpp"

namespace NAlgorithms
{
	namespace NHelper
	{
		/**
		* This function will receive the queue and construct a visual representation of it
		**/
		std::string GetQueueData(const NHuffman::PrefixQueue& queue)
		{
			std::string result;

			NHuffman::PrefixQueue tempQueue = queue;
			while (!tempQueue.empty())
			{
				result += tempQueue.front() ? "1" : "0";
				tempQueue.pop();
			}
			return result;
		}

		/**
		* This function will receive the queue and the root node
		* It will iterate through the encoded message and through the tree
		*
		* It will return the message which was encrypted with the corresponding tree
		**/
		std::string GetDecodedMessage(const NHuffman::PrefixQueue& encodedMessage, const INode* root)
		{
			std::string result;

			NHuffman::PrefixQueue tempQueue = encodedMessage;
			const INode* tempNode = root;

			while (!tempQueue.empty())
			{
				if (const LeafNode* lf = dynamic_cast<const LeafNode*>(tempNode))
				{
					result += lf->data_;
					tempNode = root;
				}
				else if (const InternalNode* in = dynamic_cast<const InternalNode*>(tempNode))
				{
					tempNode = (tempQueue.front() ? in->right_ : in->left_);
					tempQueue.pop();
				}
			}

			if (const LeafNode* lf = dynamic_cast<const LeafNode*>(tempNode))
			{
				result += lf->data_;
			}

			return result;
		}

	} // NHelper
} // NAlgorithms



