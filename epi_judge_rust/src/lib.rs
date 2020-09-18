#![allow(dead_code)]

mod anagrams;
mod is_string_permutable_to_palindrome;

use std::io::{BufRead, BufReader};
use std::path::PathBuf;
use std::sync::mpsc;
use std::thread;
use std::time::{Duration, Instant};

type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

fn get_test_data_path(filename: &str) -> Result<PathBuf> {
    let mut path = std::env::current_dir()?;
    path.push("../test_data/");
    path.push(filename);
    Ok(path)
}

pub fn read_test_data(filename: &str) -> Result<Vec<Vec<String>>> {
    let path = get_test_data_path(filename)?;
    let file = std::fs::File::open(path)?;
    let reader = BufReader::new(file);
    let mut result = vec![];
    let mut lines = reader.lines();

    // skip header row
    lines.next();

    for line in lines {
        let line = line?;
        let row = line.split('\t').map(String::from).collect::<Vec<_>>();
        result.push(row.to_vec());
    }

    Ok(result)
}

enum ExecStatus {
    Pending,
    Done,
    TimedOut,
}

pub fn run_tests<F>(func: F)
where
    F: 'static + FnOnce() + Send,
{
    // TODO measure elapsed time, improve
    // TODO handle errors: RuntimeError, TimeLimitExceeded, OtherError

    let (sender, receiver) = mpsc::channel::<ExecStatus>();
    let then = Instant::now();

    thread::spawn(move || {
        func();
        sender.send(ExecStatus::Done).unwrap();
    });

    // TODO make default timeout configurable
    match receiver.recv_timeout(Duration::from_millis(5000)) {
        Ok(_) => {
            println!("Took: {}ms", then.elapsed().as_millis());
        }
        Err(e) => {
            panic!("TimeLimitExceeded: {:?}", e);
        }
    }
}
