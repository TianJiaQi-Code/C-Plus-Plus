//template<class T>
//struct AVLTreeNode
//{
//	AVLTreeNode(const T& data)
//		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
//		, _data(data), _bf(0)
//	{}
//	AVLTreeNode<T>* _pLeft; // �ýڵ������
//	AVLTreeNode<T>* _pRight; // �ýڵ���Һ���
//	AVLTreeNode<T>* _pParent; // �ýڵ��˫��
//	T _data;
//	int _bf; // �ýڵ��ƽ������
//};

//bool Insert(const T& data)
//{
//	// 1. �Ȱ��ն����������Ĺ��򽫽ڵ���뵽AVL����
//	// ...
//	// 2. �½ڵ�����AVL����ƽ���Կ��ܻ��⵽�ƻ�����ʱ����Ҫ����ƽ�����ӣ�������Ƿ�
//	// �ƻ���AVL����ƽ����
//	/*
//	pCur�����pParent��ƽ������һ����Ҫ�������ڲ���֮ǰ��pParent
//	��ƽ�����ӷ�Ϊ���������-1��0, 1, ���������������
//	1. ���pCur���뵽pParent����ֻ࣬���pParent��ƽ������-1����
//	2. ���pCur���뵽pParent���Ҳֻ࣬���pParent��ƽ������+1����
//	��ʱ��pParent��ƽ�����ӿ��������������0������1�� ����2
//	1. ���pParent��ƽ������Ϊ0��˵������֮ǰpParent��ƽ������Ϊ����1������󱻵���
//	��0����ʱ����
//	AVL�������ʣ�����ɹ�
//	2. ���pParent��ƽ������Ϊ����1��˵������ǰpParent��ƽ������һ��Ϊ0������󱻸�
//	�³�����1����
//	ʱ��pParentΪ�������ĸ߶����ӣ���Ҫ�������ϸ���
//	3. ���pParent��ƽ������Ϊ����2����pParent��ƽ������Υ��ƽ���������ʣ���Ҫ�����
//	����ת����
//	*/
//
//	while (pParent)
//	{
//		// ����˫�׵�ƽ������
//		if (pCur == pParent->_pLeft)
//			pParent->_bf--;
//		else
//			pParent->_bf++;
//		// ���º���˫�׵�ƽ������
//		if (0 == pParent->_bf)
//		{
//			break;
//		}
//		else if (1 == pParent->_bf || -1 == pParent->_bf)
//		{
//			// ����ǰ˫�׵�ƽ��������0�������˫�׵�ƽ����ΪΪ1 ���� -1 ��˵����˫��Ϊ���Ķ�����
//			// �ĸ߶�������һ�㣬�����Ҫ�������ϵ���
//			pCur = pParent;
//			pParent = pCur->_pParent;
//		}
//		else
//		{
//			// ˫�׵�ƽ������Ϊ����2��Υ����AVL����ƽ���ԣ���Ҫ����pParent
//			// Ϊ������������ת����
//			if (2 == pParent->_bf)
//			{
//				// ...
//			}
//			else
//			{
//				// ...
//			}
//		}
//	}
//	return true;
//}

///*
//��ͼ�ڲ���ǰ��AVL����ƽ��ģ��½ڵ���뵽30��������(ע�⣺�˴���������)�У�30��
//��������
//��һ�㣬������60Ϊ���Ķ�������ƽ�⣬Ҫ��60ƽ�⣬ֻ�ܽ�60�������ĸ߶ȼ���һ�㣬����
//������һ�㣬
//���������������ᣬ����60ת��������Ϊ60��30��ֻ�ܽ������30���������������30��
//������������������ֵһ������30��С��60��ֻ�ܽ������60������������ת��ɺ󣬸��½ڵ�
//��ƽ�����Ӽ��ɡ�����ת�����У������¼��������Ҫ���ǣ�
//1. 30�ڵ���Һ��ӿ��ܴ��ڣ�Ҳ���ܲ�����
//2. 60�����Ǹ��ڵ㣬Ҳ����������
//����Ǹ��ڵ㣬��ת��ɺ�Ҫ���¸��ڵ�
//�����������������ĳ���ڵ����������Ҳ������������
//ͬѧ���ٴ˴��ɾ�һЩ��ϸ�����ӽ��л�ͼ�����Ǹ��������������ת�����
//*/
//
//void _RotateR(PNode pParent)
//{
//	// pSubL: pParent������
//	// pSubLR: pParent���ӵ��Һ��ӣ�ע�⣺��
//	PNode pSubL = pParent->_pLeft;
//	PNode pSubLR = pSubL->_pRight;
//	// ��ת���֮��30���Һ�����Ϊ˫�׵�����
//	pParent->_pLeft = pSubLR;
//	// ���30�����ӵ��Һ��Ӵ��ڣ�������˫��
//	if (pSubLR)
//		pSubLR->_pParent = pParent;
//	// 60 ��Ϊ 30���Һ���
//	pSubL->_pRight = pParent;
//	// ��Ϊ60�����ǿ�����������ڸ�����˫��ǰ�����ȱ���60��˫��
//	PNode pPParent = pParent->_pParent;
//	// ����60��˫��
//	pParent->_pParent = pSubL;
//	// ����30��˫��
//	pSubL->_pParent = pPParent;
//	// ���60�Ǹ��ڵ㣬����ָ����ڵ��ָ��
//	if (NULL == pPParent)
//	{
//		_pRoot = pSubL;
//		pSubL->_pParent = NULL;
//	}
//	else
//	{
//		// ���60����������������˫�׵���������Ҳ������������
//		if (pPParent->_pLeft == pParent)
//			pPParent->_pLeft = pSubL;
//		else
//			pPParent->_pRight = pSubL;
//	}
//	// ���ݵ�����Ľṹ���²��ֽڵ��ƽ������
//	pParent->_bf = pSubL->_bf = 0;
//}

//// ��ת֮ǰ��60��ƽ�����ӿ�����-1/0/1����ת���֮�󣬸�������������ڵ��ƽ�����ӽ��е���
//void _RotateLR(PNode pParent)
//{
//	PNode pSubL = pParent->_pLeft;
//	PNode pSubLR = pSubL->_pRight;
//	// ��ת֮ǰ������pSubLR��ƽ�����ӣ���ת���֮����Ҫ���ݸ�ƽ�����������������ڵ��ƽ������
//	int bf = pSubLR->_bf;
//	// �ȶ�30��������
//	_RotateL(pParent->_pLeft);
//	// �ٶ�90�����ҵ���
//	_RotateR(pParent);
//	if (1 == bf)
//		pSubL->_bf = -1;
//	else if (-1 == bf)
//		pParent->_bf = 1;
//}

int _Height(PNode pRoot);
bool _IsBalanceTree(PNode pRoot)
{
	// ����Ҳ��AVL��
	if (nullptr == pRoot) return true;
	// ����pRoot�ڵ��ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
	int leftHeight = _Height(pRoot->_pLeft);
	int rightHeight = _Height(pRoot->_pRight);
	int diff = rightHeight - leftHeight;
	// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
	// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
	if (diff != pRoot->_bf || (diff > 1 || diff < -1))
		return false;
	// pRoot��������������AVL���������һ����AVL��
	return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot -> _pRight);
}