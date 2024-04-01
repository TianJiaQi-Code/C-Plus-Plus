//template<class T>
//struct AVLTreeNode
//{
//	AVLTreeNode(const T& data)
//		: _pLeft(nullptr), _pRight(nullptr), _pParent(nullptr)
//		, _data(data), _bf(0)
//	{}
//	AVLTreeNode<T>* _pLeft; // 该节点的左孩子
//	AVLTreeNode<T>* _pRight; // 该节点的右孩子
//	AVLTreeNode<T>* _pParent; // 该节点的双亲
//	T _data;
//	int _bf; // 该节点的平衡因子
//};

//bool Insert(const T& data)
//{
//	// 1. 先按照二叉搜索树的规则将节点插入到AVL树中
//	// ...
//	// 2. 新节点插入后，AVL树的平衡性可能会遭到破坏，此时就需要更新平衡因子，并检测是否
//	// 破坏了AVL树的平衡性
//	/*
//	pCur插入后，pParent的平衡因子一定需要调整，在插入之前，pParent
//	的平衡因子分为三种情况：-1，0, 1, 分以下两种情况：
//	1. 如果pCur插入到pParent的左侧，只需给pParent的平衡因子-1即可
//	2. 如果pCur插入到pParent的右侧，只需给pParent的平衡因子+1即可
//	此时：pParent的平衡因子可能有三种情况：0，正负1， 正负2
//	1. 如果pParent的平衡因子为0，说明插入之前pParent的平衡因子为正负1，插入后被调整
//	成0，此时满足
//	AVL树的性质，插入成功
//	2. 如果pParent的平衡因子为正负1，说明插入前pParent的平衡因子一定为0，插入后被更
//	新成正负1，此
//	时以pParent为根的树的高度增加，需要继续向上更新
//	3. 如果pParent的平衡因子为正负2，则pParent的平衡因子违反平衡树的性质，需要对其进
//	行旋转处理
//	*/
//
//	while (pParent)
//	{
//		// 更新双亲的平衡因子
//		if (pCur == pParent->_pLeft)
//			pParent->_bf--;
//		else
//			pParent->_bf++;
//		// 更新后检测双亲的平衡因子
//		if (0 == pParent->_bf)
//		{
//			break;
//		}
//		else if (1 == pParent->_bf || -1 == pParent->_bf)
//		{
//			// 插入前双亲的平衡因子是0，插入后双亲的平衡因为为1 或者 -1 ，说明以双亲为根的二叉树
//			// 的高度增加了一层，因此需要继续向上调整
//			pCur = pParent;
//			pParent = pCur->_pParent;
//		}
//		else
//		{
//			// 双亲的平衡因子为正负2，违反了AVL树的平衡性，需要对以pParent
//			// 为根的树进行旋转处理
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
//上图在插入前，AVL树是平衡的，新节点插入到30的左子树(注意：此处不是左孩子)中，30左
//子树增加
//了一层，导致以60为根的二叉树不平衡，要让60平衡，只能将60左子树的高度减少一层，右子
//树增加一层，
//即将左子树往上提，这样60转下来，因为60比30大，只能将其放在30的右子树，而如果30有
//右子树，右子树根的值一定大于30，小于60，只能将其放在60的左子树，旋转完成后，更新节点
//的平衡因子即可。在旋转过程中，有以下几种情况需要考虑：
//1. 30节点的右孩子可能存在，也可能不存在
//2. 60可能是根节点，也可能是子树
//如果是根节点，旋转完成后，要更新根节点
//如果是子树，可能是某个节点的左子树，也可能是右子树
//同学们再此处可举一些详细的例子进行画图，考虑各种情况，加深旋转的理解
//*/
//
//void _RotateR(PNode pParent)
//{
//	// pSubL: pParent的左孩子
//	// pSubLR: pParent左孩子的右孩子，注意：该
//	PNode pSubL = pParent->_pLeft;
//	PNode pSubLR = pSubL->_pRight;
//	// 旋转完成之后，30的右孩子作为双亲的左孩子
//	pParent->_pLeft = pSubLR;
//	// 如果30的左孩子的右孩子存在，更新亲双亲
//	if (pSubLR)
//		pSubLR->_pParent = pParent;
//	// 60 作为 30的右孩子
//	pSubL->_pRight = pParent;
//	// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
//	PNode pPParent = pParent->_pParent;
//	// 更新60的双亲
//	pParent->_pParent = pSubL;
//	// 更新30的双亲
//	pSubL->_pParent = pPParent;
//	// 如果60是根节点，根新指向根节点的指针
//	if (NULL == pPParent)
//	{
//		_pRoot = pSubL;
//		pSubL->_pParent = NULL;
//	}
//	else
//	{
//		// 如果60是子树，可能是其双亲的左子树，也可能是右子树
//		if (pPParent->_pLeft == pParent)
//			pPParent->_pLeft = pSubL;
//		else
//			pPParent->_pRight = pSubL;
//	}
//	// 根据调整后的结构更新部分节点的平衡因子
//	pParent->_bf = pSubL->_bf = 0;
//}

//// 旋转之前，60的平衡因子可能是-1/0/1，旋转完成之后，根据情况对其他节点的平衡因子进行调整
//void _RotateLR(PNode pParent)
//{
//	PNode pSubL = pParent->_pLeft;
//	PNode pSubLR = pSubL->_pRight;
//	// 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
//	int bf = pSubLR->_bf;
//	// 先对30进行左单旋
//	_RotateL(pParent->_pLeft);
//	// 再对90进行右单旋
//	_RotateR(pParent);
//	if (1 == bf)
//		pSubL->_bf = -1;
//	else if (-1 == bf)
//		pParent->_bf = 1;
//}

int _Height(PNode pRoot);
bool _IsBalanceTree(PNode pRoot)
{
	// 空树也是AVL树
	if (nullptr == pRoot) return true;
	// 计算pRoot节点的平衡因子：即pRoot左右子树的高度差
	int leftHeight = _Height(pRoot->_pLeft);
	int rightHeight = _Height(pRoot->_pRight);
	int diff = rightHeight - leftHeight;
	// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
	// pRoot平衡因子的绝对值超过1，则一定不是AVL树
	if (diff != pRoot->_bf || (diff > 1 || diff < -1))
		return false;
	// pRoot的左和右如果都是AVL树，则该树一定是AVL树
	return _IsBalanceTree(pRoot->_pLeft) && _IsBalanceTree(pRoot -> _pRight);
}