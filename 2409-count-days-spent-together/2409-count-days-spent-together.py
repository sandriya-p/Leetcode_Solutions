class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        months = [31,28,31,30,31,30,31,31,30,31,30,31]

        a1 = arriveAlice
        a2 = leaveAlice
        b1 = arriveBob
        b2 = leaveBob

        a11= a1.split('-')
        a12= a2.split('-')
        b11= b1.split('-')
        b12= b2.split('-')

        Alice_start_month= int(a11[0])
        Alice_start_date = int(a11[1])
        Alice_end_month= int(a12[0])
        Alice_end_date = int(a12[1])

        Bob_start_month= int(b11[0])
        Bob_start_date = int(b11[1])
        Bob_end_month= int(b12[0])
        Bob_end_date = int(b12[1])

        Alice_start_day = sum(months[0:Alice_start_month-1]) + Alice_start_date
        Alice_end_day = sum(months[0:Alice_end_month-1]) + Alice_end_date
        Bob_start_day = sum(months[0:Bob_start_month-1]) + Bob_start_date
        Bob_end_day = sum(months[0:Bob_end_month-1]) + Bob_end_date

        start_day = max( Alice_start_day, Bob_start_day)
        end_day = min( Alice_end_day, Bob_end_day)

        if start_day>end_day:
            return 0 
        else:
            days = end_day - start_day +1
            return days
        



        


        