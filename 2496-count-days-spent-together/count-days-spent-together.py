from datetime import date

class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        def compute(s: str) -> date:
            return date(2026, int(s[:2]), int(s[3:]))

        start = max(compute(arriveAlice), compute(arriveBob))
        end = min(compute(leaveAlice), compute(leaveBob))

        return max(0, (end - start).days + 1)