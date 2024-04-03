#include <iostream>
using namespace std;

//// �ڵ����ɫ
//enum Color { RED, BLACK };
//// ������ڵ�Ķ���
//template<class ValueType>
//struct RBTreeNode
//{
//	RBTreeNode(const ValueType& data = ValueType()��Color color = RED)
//		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
//		, _data(data), _color(color)
//	{}
//	RBTreeNode<ValueType>* _pLeft; // �ڵ������
//	RBTreeNode<ValueType>* _pRight; // �ڵ���Һ���
//	RBTreeNode<ValueType>* _pParent; // �ڵ��˫��(�������Ҫ��ת��Ϊ��ʵ�ּ򵥸������ֶ�)
//	ValueType _data; // �ڵ��ֵ��
//	Color _color; // �ڵ����ɫ
//};

//template<class ValueType>
//class RBTree
//{
//	//����
//	bool Insert(const ValueType& data)
//	{
//		PNode& pRoot = GetRoot();
//		if (nullptr == pRoot)
//		{
//			pRoot = new Node(data, BLACK);
//			// ����˫��Ϊͷ�ڵ�
//			pRoot->_pParent = _pHead;
//			_pHead->_pParent = pRoot;
//		}
//		else
//		{
//			// 1. ���ն�������������ʽ�����½ڵ�
//			// 2. ����½ڵ����󣬺�����������Ƿ��쵽�ƻ���
//			// ������ֱ���˳�������Ժ����������ת��ɫ����
//		}
//		// ���ڵ����ɫ���ܱ��޸ģ�����Ļغ�ɫ
//		pRoot->_color = BLACK;
//		_pHead->_pLeft = LeftMost();
//		_pHead->_pRight = RightMost();
//		return true;
//	}
//private:
//	PNode& GetRoot() { return _pHead->_pParent; }
//	// ��ȡ���������С�ڵ㣬�������ڵ�
//	PNode LeftMost();
//	// ��ȡ����������ڵ㣬�����Ҳ�ڵ�
//	PNode RightMost();
//private:
//	PNode _pHead;
//};

//bool Insert(const ValueType& data)
//{
//	// ...
//	// �½ڵ����������˫�׽ڵ����ɫΪ��ɫ����Υ������3������������һ��ĺ�ɫ���
//	while (pParent && RED == pParent->_color)
//	{
//		// ע�⣺grandFatherһ������
//		// ��ΪpParent���ڣ��Ҳ��Ǻ�ɫ�ڵ㣬��pParentһ�����Ǹ�������һ����˫��
//		PNode grandFather = pParent->_pParent;
//		// ������������
//		if (pParent == grandFather->_pLeft)
//		{
//			PNode unclue = grandFather->_pRight;
//			// �����������ڵ���ڣ���Ϊ��
//			if (unclue && RED == unclue->_color)
//			{
//				pParent->_color = BLACK;
//				unclue->_color = BLACK;
//				grandFather->_color = RED;
//				pCur = grandFather;
//				pParent = pCur->_pParent;
//			}
//			else
//			{
//				// ����壺����ڵ㲻���ڣ���������ڵ������Ϊ��
//				if (pCur == pParent->_pRight)
//				{
//					_RotateLeft(pParent);
//					swap(pParent, pCur);
//				}
//				// ��������ת���������
//				grandFather->_color = RED;
//				pParent->_color = BLACK;
//				_RotateRight(grandFather);
//			}
//		}
//		else
//		{
//			// �Ҳ���ѧ�����Լ��������
//		}
//	}
//	// ...
//}

bool IsValidRBTree()
{
	PNode pRoot = GetRoot();
	// ����Ҳ�Ǻ����
	if (nullptr == pRoot)
		return true;
	// �����ڵ��Ƿ��������
	if (BLACK != pRoot->_color)
	{
		cout << "Υ����������ʶ������ڵ����Ϊ��ɫ" << endl;
		return false;
	}
	// ��ȡ����һ��·���к�ɫ�ڵ�ĸ���
	size_t blackCount = 0;
	PNode pCur = pRoot;
	while (pCur)
	{
		if (BLACK == pCur->_color)
			blackCount++;
		pCur = pCur->_pLeft;
	}
	// ����Ƿ��������������ʣ�k������¼·���к�ɫ�ڵ�ĸ���
	size_t k = 0;
	return _IsValidRBTree(pRoot, k, blackCount);
}
bool _IsValidRBTree(PNode pRoot, size_t k, const size_t blackCount)
{
	//�ߵ�null֮���ж�k��black�Ƿ����
	if (nullptr == pRoot)
	{
		if (k != blackCount)
		{
			cout << "Υ�������ģ�ÿ��·���к�ɫ�ڵ�ĸ���������ͬ" << endl;
			return false;
		}
		return true;
	}
	// ͳ�ƺ�ɫ�ڵ�ĸ���
	if (BLACK == pRoot->_color)
		k++;
	// ��⵱ǰ�ڵ�����˫���Ƿ�Ϊ��ɫ
	PNode pParent = pRoot->_pParent;
	if (pParent && RED == pParent->_color && RED == pRoot->_color)
	{
		cout << "Υ����������û������һ��ĺ�ɫ�ڵ�" << endl;
		return false;
	}
	return _IsValidRBTree(pRoot->_pLeft, k, blackCount)
		&& _IsValidRBTree(pRoot->_pRight, k, blackCount);
}