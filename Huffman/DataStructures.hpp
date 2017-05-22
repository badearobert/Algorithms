#pragma once
/******************************************************************************
* Copyright (C) 22/05/2017
*
* @file         DataStructures.hpp
* @project		Algorithms / Huffman
* @author       Robert Badea
* @url			www.robertbadea.ro
******************************************************************************
* File containing the used data structure, independent of the algorithm
******************************************************************************/
namespace NAlgorithms
{
	/**
	* Interface for nodes. 
	* All nodes contain the frequency.
	* The class cannot be instantiated (protected ctor)
	**/
	class INode
	{
	public:
		const int freq_;
		virtual ~INode() {}

	protected:
		INode(int freq) : freq_(freq) {}
	};

	/**
	* Container node, have left and right child
	* Container frequency is the sum of the left & right nodes.
	**/
	class InternalNode : public INode
	{
	public:
		INode *const left_;
		INode *const right_;

		InternalNode(INode* left, INode* right)
			: INode(left->freq_ + right->freq_)
			, left_(left)
			, right_(right)
		{
		}
		~InternalNode()
		{
			delete left_;
			delete right_;
		}
	};

	/**
	* Leaf node, contain the actual character
	**/
	class LeafNode : public INode
	{
	public:
		const char data_;

		LeafNode(int freq, char data)
			: INode(freq)
			, data_(data)
		{
		}
	};

	/**
	* Function to compare two INode pointers.
	* Separated from base class due to it being abstract
	**/
	struct NodeCmp
	{
		bool operator()(const INode* lhs, const INode* rhs) const 
		{ 
			return lhs->freq_ > rhs->freq_; 
		}
	};

} // NAlgorithms