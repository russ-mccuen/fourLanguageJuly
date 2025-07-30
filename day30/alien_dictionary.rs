use std::collections::{HashMap, HashSet, VecDeque};

fn alien_order(words: Vec<&str>) -> Option<String> {
    let mut graph: HashMap<char, HashSet<char>> = HashMap::new();
    let mut in_degree: HashMap<char, usize> = HashMap::new();

    println!("Input words: {:?}", words);

    // Initialize in-degree
    for word in &words {
        for c in word.chars() {
            in_degree.entry(c).or_insert(0);
        }
    }

    println!("Initial in-degree map: {:?}", in_degree);

    // Build graph
    for pair in words.windows(2) {
        let (first, second) = (pair[0], pair[1]);
        let mut found = false;
        for (c1, c2) in first.chars().zip(second.chars()) {
            if c1 != c2 {
                let entry = graph.entry(c1).or_default();
                if entry.insert(c2) {
                    *in_degree.entry(c2).or_insert(0) += 1;
                }
                found = true;
                break;
            }
        }
        if !found && first.len() > second.len() {
            return None;
        }
    }

    println!("Graph (edges):");
    for (k, v) in &graph {
        let edges: Vec<char> = v.iter().cloned().collect();
        println!("  {} → {:?}", k, edges);
    }

    println!("Updated in-degree map: {:?}", in_degree);

    let mut queue = VecDeque::new();
    for (&c, &deg) in &in_degree {
        if deg == 0 {
            queue.push_back(c);
        }
    }

    println!("Starting BFS with queue: {:?}", queue);

    let mut result = String::new();
    while let Some(c) = queue.pop_front() {
        println!("Visiting: {}", c);
        result.push(c);
        if let Some(neighbors) = graph.get(&c) {
            for &n in neighbors {
                if let Some(d) = in_degree.get_mut(&n) {
                    *d -= 1;
                    if *d == 0 {
                        queue.push_back(n);
                    }
                }
            }
        }
    }

    if result.len() == in_degree.len() {
        println!("Alien dictionary order: {}", result);
        Some(result)
    } else {
        println!("Invalid input — no valid order exists.");
        None
    }
}

fn main() {
    alien_order(vec!["wrt", "wrf", "er", "ett", "rftt"]);
}
