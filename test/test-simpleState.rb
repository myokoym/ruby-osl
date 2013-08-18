require "osl"

class SimpleStateTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(SimpleState.new)
  end
end
