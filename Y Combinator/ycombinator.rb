puts ->() {

# Step-improver for factorial
fact_improver = ->(partial) {
  ->(n) { n.zero? ? 1 : n * partial.(n-1) }
}

# Applicative Order Y Combinator
# otherwise known as Z Combinator or Fixpoint Combinator
y = ->(f) {
  ->(x) { f.(->(v) { x.(x).(v) }) }.(
  ->(x) { f.(->(v) { x.(x).(v) }) } )
}

y = ->(f) {
  ->(x) {
    f.(->(v) { x.(x).(v) })
  }.(
    ->(x) {
      f.(->(v) { x.(x).(v) })
    }
  )
}

# Function y calculates the fixpoint of a function.
fact = y.(fact_improver)

fact = fact_improver.(fact) # Does not change the effect of fact at all.
# This shows that: fact is the fixpoint of fact_improver.
#
# Conclusion:
#  Higher-order functions have fixpoints as well (which are functions).

fact.(5)  # 120

}.()
