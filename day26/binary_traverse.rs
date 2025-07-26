use rand::random;
use std::collections::VecDeque;

#[derive(Debug)]
struct TreeNode {
    val: i32,
    left: Option<Box<TreeNode>>,
    right: Option<Box<TreeNode>>,
}

impl TreeNode {
    fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

// Manual Clone implementation
impl Clone for TreeNode {
    fn clone(&self) -> Self {
        TreeNode {
            val: self.val,
            left: self.left.clone(),
            right: self.right.clone(),
        }
    }
}

fn build_tree_from_list(data: &[Option<i32>]) -> Option<Box<TreeNode>> {
    if data.is_empty() || data[0].is_none() {
        return None;
    }

    let mut nodes: Vec<Option<Box<TreeNode>>> = data
        .iter()
        .map(|&x| x.map(|v| Box::new(TreeNode::new(v))))
        .collect();

    let len = nodes.len();
    for i in 0..len {
        if nodes[i].is_some() {
            let (left_idx, right_idx) = (2 * i + 1, 2 * i + 2);
            let node_ptr: *mut Option<Box<TreeNode>> = &mut nodes[i];
            unsafe {
                let node = (*node_ptr).as_mut().unwrap();
                if left_idx < len {
                    node.left = nodes[left_idx].take();
                }
                if right_idx < len {
                    node.right = nodes[right_idx].take();
                }
            }
        }
    }

    nodes[0].take()
}

fn tree_to_list(root: &Option<Box<TreeNode>>) -> Vec<Option<i32>> {
    let mut result = vec![];
    let mut queue = VecDeque::new();
    queue.push_back(root.clone());

    while let Some(node_opt) = queue.pop_front() {
        if let Some(node) = node_opt {
            result.push(Some(node.val));
            queue.push_back(node.left.clone());
            queue.push_back(node.right.clone());
        } else {
            result.push(None);
        }
    }

    while matches!(result.last(), Some(None)) {
        result.pop();
    }

    result
}

fn main() {
    let len = 10;
    let mut list: Vec<Option<i32>> = (0..len)
        .map(|_| Some(random::<i32>() % 100))
        .collect();

    // Introduce Nones
    for i in 0..len {
        if random::<u8>() % 4 == 0 {
            list[i] = None;
        }
    }

    println!("Input list: {:?}", list);
    let tree = build_tree_from_list(&list);
    let flat = tree_to_list(&tree);
    println!("Flattened: {:?}", flat);
}
