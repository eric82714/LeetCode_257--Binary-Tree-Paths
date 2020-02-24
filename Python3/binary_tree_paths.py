# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        def storePaths(root, path):
            if not root: return None

            if not root.right and not root.left:
                result.append(path + str(root.val))
                return None
            
            path += str(root.val) + "->"
            
            storePaths(root.left, path)
            storePaths(root.right, path)
        
        result = []
        storePaths(root, "")
        
        return result
