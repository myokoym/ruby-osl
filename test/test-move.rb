require "osl"

class MoveTest < Test::Unit::TestCase
  def test_new
    assert_not_nil(Osl::Move.new)
  end
end
