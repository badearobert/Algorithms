/******************************************************************************
* Copyright (C) 22/05/2017
*
* @file         Huffman.cpp
* @project		Algorithms / Huffman
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************/
//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include "Huffman.hpp"

namespace NAlgorithms
{
	namespace NHuffman
	{
		/**
		* Function that will generate the tree based on a given frequency map
		* The frequency map contains the frequences for the characters from a string
		* Returns the root node
		**/
		INode* GenerateTree(FrequencyMap& frequencyMap)
		{
			INode* root = nullptr;
			std::priority_queue<INode*, std::vector<INode*>, NodeCmp> priorityTree;
			for (auto const& i : frequencyMap)
			{
				priorityTree.push(new LeafNode(i.second, i.first));
			}

			while (priorityTree.size() > 1)
			{
				INode* childL = priorityTree.top();
				priorityTree.pop();

				INode* childR = priorityTree.top();
				priorityTree.pop();
				INode* parent = new InternalNode(childL, childR);
				priorityTree.push(parent);
			}
			return priorityTree.top();
		}

		void GenerateCode(INode* node, PrefixQueue prefix, HuffmanCodes& codes)
		{
			if (const LeafNode* lf = dynamic_cast<const LeafNode*>(node))
			{
				codes[lf->data_] = prefix;
			}
			else if (const InternalNode* in = dynamic_cast<const InternalNode*>(node))
			{
				PrefixQueue leftSide = prefix;
				leftSide.push(false);
				GenerateCode(in->left_, leftSide, codes);

				PrefixQueue rightSide = prefix;
				rightSide.push(true);
				GenerateCode(in->right_, rightSide, codes);
			}
		}
	} // NHuffman
} // NAlgorithms