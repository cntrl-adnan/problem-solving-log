package backtracking;

import java.util.*;

class CombinationSum {

    public void combinationSumHelper(
            List<List<Integer>> result,
            List<Integer> current,
            int[] candidates,
            int i,
            int target
    ) {

        if (i >= candidates.length || target < 0)
            return;

        if (target == 0) {
            result.add(new ArrayList<>(current));
            return;
        }

        // Skip current element
        combinationSumHelper(
                result,
                current,
                candidates,
                i + 1,
                target
        );

        // Take current element
        if (candidates[i] <= target) {

            current.add(candidates[i]);

            combinationSumHelper(
                    result,
                    current,
                    candidates,
                    i,
                    target - candidates[i]
            );

            current.remove(current.size() - 1); // backtrack
        }
    }


    public List<List<Integer>> combinationSum(
            int[] candidates,
            int target
    ) {

        List<List<Integer>> result = new ArrayList<>();
        List<Integer> current = new ArrayList<>();

        combinationSumHelper(
                result,
                current,
                candidates,
                0,
                target
        );

        return result;
    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of candidates: ");
        int n = sc.nextInt();

        int[] candidates = new int[n];

        System.out.println("Enter elements:");
        for(int i=0;i<n;i++){
            candidates[i] = sc.nextInt();
        }

        System.out.print("Enter target: ");
        int target = sc.nextInt();

        CombinationSum obj = new CombinationSum();

        List<List<Integer>> ans =
                obj.combinationSum(candidates, target);

        System.out.println("\nCombinations:");

        for(List<Integer> list : ans){
            System.out.println(list);
        }

        sc.close();
    }
}