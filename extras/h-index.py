"""The h-index is a metric that measures both the productivity and citation impact of a researcher. A researcher's h-index is the larger number h such that the researcher has published h papers that have each been cited at least h times.

A researcher that has published papers A, B, C, D, E, F, G, H I, which have been cited 1, 4, 1, 4, 2, 1, 3, 5, and 6 times respectively would have a h-index of 4, since they have 4 papers that have been published at least 4 times.

This module provides a function to enable the h-index of a researcher to be computed given a list of their publications and number of citations.
"""
from typing import List


def compute_h_index(paper_citations_count: List[int]) -> int:
    """Compute the h-index of a researcher.

    Args:
        paper_citations_count (List[int]): The number of citations received by each paper the researcher has published.

    Returns:
        int: The h-index of the researcher.
    """
    sorted_paper_citations_count = sorted(paper_citations_count)
    paper_count = len(paper_citations_count)

    for i, citation_count in enumerate(sorted_paper_citations_count):
        number_of_remaining_papers = paper_count - i

        if citation_count >= number_of_remaining_papers:
            return number_of_remaining_papers


def main():
    """Run main function."""
    researcher_citations = [1, 4, 1, 4, 2, 1, 3, 5, 6]
    researcher_h_index = compute_h_index(researcher_citations)
    print(researcher_h_index)


if __name__ == "__main__":
    main()
